// Fp cost = 5 - stun_skill/30 ( that is 5~2)   +    5 (if 点中!) 
////#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

#define stun_point ({ "青灵", "缺盆", "檀中", "筑宾", "肩贞" })

int block_victim(object me, object victim); 
int stun_work(object me, object victim);

int cmd_stun()
{
	int skill, fp_cost, delay;
	object me, victim;
	
	me = this_player();
    if( me->query_temp("stun_busy") )
    	return notify_fail("\n *** 你还在等待机会点穴，不能分心。*** \n");
    if( me->query_temp("busy") )
    	return notify_fail("\n  你正在专心作别的事情，不能分心点穴。\n");
	victim = me->query_attacker();
	if( !victim ) return notify_fail("你没在战斗中，找不到对手在哪里!\n");
		
	if( !skill = (int)me->query_skill("force-stun") )
		return notify_fail( "你没有练过点穴，不了解穴道位置，练个几年再来吧 !!!\n");

	fp_cost = 5 - skill / 30;
	if( !fp_cost || (int)me->query("force_points") < (fp_cost + 5) )
		return notify_fail("\n *** 你的内力不足！*** \n");
	else
		me->add("force_points", -fp_cost );


	tell_object(me, set_color("\n *** 你全神贯注，开始要找机会施展你点穴的神技 ! ***\n", "HIC",me) );

	delay = 15 - skill/20 - random((int)me->query("force_effect"));
	if( delay < 1 ) delay = 1;
	me->set_temp("stun_busy",1);
	me->set_temp("busy",1);
	call_out("stun_work", delay, me, victim);
	return 1;
}

int stun_work(object me, object victim)
{
	int skill, chance;
	string loc;
	object weapon, *attackers;

	if ( !me ) return 1;
	me->delete_temp("stun_busy");
	me->delete_temp("busy");
	if ( ! me->query_attackers() || !victim) {
		tell_object(me,"你的战斗结束了，不需要点穴了! \n");
		return 1;
	}

	skill = (int)me->query_skill("force-stun");
	if( weapon = me->query("weapon1") )
		switch( weapon->query("type") ) {
			case "longblade" : 	skill *= 5;		break;
			case "bo"        :  skill *= 7;		break;
			case "shortblade":  skill *= 5;		break;
			case "dagger"    : 	skill *= 9;		break;
			case "blunt"     : 	skill *= 0;		break;
			case "axe"       : 	skill *= 0;		break;
			case "thrusting" : 	skill *= 6;		break;
			case "polearm"   : 	skill *= 0;		break;
			case "chain"     :  skill *= 0;		break;
			case "whip"      : 	skill *= 7;		break;
			default          :	skill *= 0;
		}
	// unarm stun.
	else skill *= 10;
	
	skill /= 10;
	skill += (int)me->query_stat("str")*2+(int)me->query_stat("int");
	skill -= (int)victim->query_stat("dex")*2 +(int)victim->query_stat("int");
	if (intp(victim->query("stun_difficulty")) )
	      if( random(skill) < (58 + (int)victim->query("stun_difficulty")) ) {
		tell_object(me,set_color("\n *** 哇!!! 没点到! 看来你学艺不精哦! *** \n", "HIG",me) );
		return 1;
		}
	
	block_victim(me, victim);
	return  1;
}

int block_victim( object me, object victim )
{
	int my_str, vic_kar, times;

	tell_object( me, set_color( 
		"\n *** 你飞快的向对方一点，点到了"+victim->query("c_name")+
		"的"+stun_point[random(5)]+"穴，它无法攻击了!!! ***\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"电光火石的一点，点到你的穴道筋脉。\n", "HIM",victim));

	tell_room( environment(me), 
		me->query("c_name")+"突然伸出手指飞快地往"+
		victim->query("c_name")+"的身上一点。\n\n" ,
		({ me, victim }) );

	my_str = me->query_stat("str");
	vic_kar = victim->query_stat("karma");
        times= ( my_str - vic_kar ) / 4;
        if( times <= 1 ) times = 1  + random( (int)me->query("force_effect") + 1) / 2;

	me->add("force_points", -5 );
	victim->block_attack(times*2);
	victim->set_temp("msg_stop_attack", 
		set_color("( 你觉得被点中的部位酸麻难当，一点力气也使不出来。 )\n", "HIM", victim) );
	return 1;
}

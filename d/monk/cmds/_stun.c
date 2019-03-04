// Fp cost = 5 - stun_skill/30 ( that is 5~2)   +    5 (if ����!) 
////#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

#define stun_point ({ "����", "ȱ��", "̴��", "����", "����" })

int block_victim(object me, object victim); 
int stun_work(object me, object victim);

int cmd_stun()
{
	int skill, fp_cost, delay;
	object me, victim;
	
	me = this_player();
    if( me->query_temp("stun_busy") )
    	return notify_fail("\n *** �㻹�ڵȴ������Ѩ�����ܷ��ġ�*** \n");
    if( me->query_temp("busy") )
    	return notify_fail("\n  ������ר����������飬���ܷ��ĵ�Ѩ��\n");
	victim = me->query_attacker();
	if( !victim ) return notify_fail("��û��ս���У��Ҳ�������������!\n");
		
	if( !skill = (int)me->query_skill("force-stun") )
		return notify_fail( "��û��������Ѩ�����˽�Ѩ��λ�ã��������������� !!!\n");

	fp_cost = 5 - skill / 30;
	if( !fp_cost || (int)me->query("force_points") < (fp_cost + 5) )
		return notify_fail("\n *** ����������㣡*** \n");
	else
		me->add("force_points", -fp_cost );


	tell_object(me, set_color("\n *** ��ȫ���ע����ʼҪ�һ���ʩչ���Ѩ���� ! ***\n", "HIC",me) );

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
		tell_object(me,"���ս�������ˣ�����Ҫ��Ѩ��! \n");
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
		tell_object(me,set_color("\n *** ��!!! û�㵽! ������ѧ�ղ���Ŷ! *** \n", "HIG",me) );
		return 1;
		}
	
	block_victim(me, victim);
	return  1;
}

int block_victim( object me, object victim )
{
	int my_str, vic_kar, times;

	tell_object( me, set_color( 
		"\n *** ��ɿ����Է�һ�㣬�㵽��"+victim->query("c_name")+
		"��"+stun_point[random(5)]+"Ѩ�����޷�������!!! ***\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"����ʯ��һ�㣬�㵽���Ѩ��������\n", "HIM",victim));

	tell_room( environment(me), 
		me->query("c_name")+"ͻȻ�����ָ�ɿ����"+
		victim->query("c_name")+"������һ�㡣\n\n" ,
		({ me, victim }) );

	my_str = me->query_stat("str");
	vic_kar = victim->query_stat("karma");
        times= ( my_str - vic_kar ) / 4;
        if( times <= 1 ) times = 1  + random( (int)me->query("force_effect") + 1) / 2;

	me->add("force_points", -5 );
	victim->block_attack(times*2);
	victim->set_temp("msg_stop_attack", 
		set_color("( ����ñ����еĲ�λ�����ѵ���һ������Ҳʹ�������� )\n", "HIM", victim) );
	return 1;
}

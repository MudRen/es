//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me,*who_fight;
	int sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("你到底想干嘛啦?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("你正专心的作其他的事?\n");
	if ( ! arg ) return notify_fail("你想绞杀谁?\n");
	if ( !(target = present( arg,environment(this_player()))) )
		return notify_fail("这里没有叫"+arg+"的东西。\n");
	if ( target == this_player() )
		return notify_fail("你把自己高高的挂在一棵树上....\n");
	if ( ! living(target) ) 
		return notify_fail("你用力的勒住"
			+target->query("c_name")+"但是什麽事也没发生。\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想绞杀谁?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
	if( !skill = (int)me->query_skill("hang") )
	                return notify_fail( "你没有学过绞杀技巧!!无法绞杀!!\n");
	if ( target->query("no_attack") ) {
	        write("这家伙－－－不能杀。\n");
	        return 1;
	}
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("你不能 PK 他 !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("你没有武器，无法绞杀敌人 !!\n");	
	if ( (string)weapon->query("type") != "whip" )
		return notify_fail("你的武器不趁手，无法绞杀 !!\n");
        who_fight = (object *)target->query_attacker("who_protect");
        level = me->query_level();
        skill = me->query_skill("hang");
        sp_cost = 180 - level*2 - skill;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("你的精神太差了，无法专心进行绞杀！\n");
        if( !me->query_attacker(); ) { 

   	tell_object( me, set_color( 
		"你偷偷摸摸的绕到" + target->query("c_name") + "後，准备随时给它一个绞杀..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"偷偷走到你後面，不知道要干什麽?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"偷偷摸摸的绕到"+
		target->query("c_name")+"的身後，不知道要干什麽?\n\n" ,
		({ me, target }) );
        me->set("spell_points",(int)me->query("spell_points")-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 3, me, target, weapon);
                return 1;
                       }
        write("你正忙於战斗，不能分心去作别的事情....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int dam,skill1,skill2,my_str,my_kar,wc;
   
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   my_kar = me->query_stat("kar");
   dam = my_str + my_kar - 3*(int)target->query_stat("dex") + skill2/2 + wc;
   if (dam < 10) dam = 10; 
   if (dam > 30) dam = 30;
   if (skill1/3 + skill2/5 + wc + random(my_kar) - 2*(int)target->query_stat("dex") < 0) {
      tell_object( me, set_color( 
		"\n 你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子挥去\n"
		"可惜被他闪过了....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"想要用"+weapon->query("c_name")+"绞杀你，还好你闪开了。\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"将手中的"+weapon->query("c_name")+"挥向"+
		target->query("c_name")+"的脖子，但是没套中目标。\n\n" ,
		({ me, target }) );
                me->set("stop_attack",2);
                target->kill_ob(me);
                me->kill_ob(target);
                return 1;
       }
   	tell_object( me, set_color( 
		"你成功用手中的" + weapon->query("c_name") + "绞杀" + target->query("c_name") +
		"，使他受到严重的伤害。\n\n", "HIY",me) );
		
	tell_object(target, set_color( "\n" +
		me->query("c_name")+ "用手中的" + weapon->query("c_name") + "缠住你的脖子。\n"
		"你感觉到一种窒息般的痛苦。\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"用手中的"+ weapon->query("c_name") + "缠住" +
		target->query("c_name")+"的脖子，使得他露出非常痛苦的表情。\n\n" ,
		({ me, target }) );
   target->set("stop_attack",4);
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 12 );
   target->kill_ob(me);
   me->kill_ob(target);
   return 1;
}
int help()
{
    write(
@C_LONG
指令格式: hang + <指定对象>

使用鞭类武器时，冒险者有能力绞杀毫无戒心的敌人。
若施术成功，受术者不但本身受到伤害，且力量及敏捷均暂时性
下降，且若干回合无法任意行动，而施术者为维持绞杀的效果，
则需花费大量的精神力以控制对方的行动。
C_LONG
    );
    return 1;
}    

#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/gi_mei"
#define GONFU_NAME   "gi-mei"

inherit DAEMON;

int eungon(object me, int level)
{
	if( (int)me->query("load") > (int)me->query("max_load") ) {
		tell_object( me, 
			"你携带太多东西, 无法施展身法!\n" );
		return 0;
	}
	tell_object(me, 
		"\n『身灭灭己，寂灭为乐』你全身运功\，准备使出「"+
		to_chinese(GONFU_NAME)+"」!!\n" );

	tell_room( environment(me), 
		me->query("c_name")+
		"轻叹一声，双掌合十，准备使用"+to_chinese(GONFU_NAME)+"。\n", me);

	me->set("defense_skill", MARTIAL_NAME); 
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if( me->query("monk_gonfu/gi-mei") == 35 )
            me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
	if( me->query_temp("gonfu_top") && me->query_temp("eungon_times") > 0 ) return;
	if( !me->query_temp("gonfu_busy") ) return;
	if( me->query_temp("gonfu_top") )
	    me->set_temp("gonfu_top",0);
	tell_object(me, 
		"\n\n你吸了一口气, 停止使用"+to_chinese(GONFU_NAME)+"。\n" );
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"轻轻的吐出一口气，收式停功。\n", me);
 
// 	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}

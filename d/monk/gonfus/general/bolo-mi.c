#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/bolo_mi"
#define GONFU_NAME   "bolo-mi"

inherit DAEMON;

int eungon(object me, int level)
{
	if( (int)me->query("load") > (int)me->query("max_load")*2/3 ) {
		tell_object(me,
			"你带太多东西了, 使不出腿法!\n");
		return 0;
	}

	tell_object(me, 
		"\n『般若波罗密...』你运功\於腿，准备使出「"+to_chinese(GONFU_NAME)+"」!\n" );

	tell_room( environment(me), 
		"\n"+me->query("c_name")+
		"大喝一声，身形虚浮，准备使用"+to_chinese(GONFU_NAME)+"。\n", me);

	me->set("defense_skill", MARTIAL_NAME); 
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if( me->query("monk_gonfu/bolo-mi") == 35 )
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
	 	me->query("c_name")+"轻轻的吐出一口气，收式而立。\n" , me);

	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}

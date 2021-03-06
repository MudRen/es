#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "tanlo"

inherit DAEMON;

int enhant(object me, int level)
{
	tell_object(me, can_read_chinese(me)?
		"\n你开始将内力聚於脚尖, 准备使出「"+
		to_chinese(GONFU_NAME)+"」!!\n":
		"You prepare to use "+GONFU_NAME+" step!!\n");

	tell_room( environment(me), ({
		"\n"+me->query("cap_name")+" is preparing to use "+GONFU_NAME+
		" gonfu!\n", "\n"+me->query("c_cap_name")+
		"突然身形一变，脚步不知依照甚麽顺序而走了起来。\n" }), me);

	me->set("defense_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("attack_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	tell_object(me, can_read_chinese(me)?
		"你吸了一口气, 停止使用"+to_chinese(GONFU_NAME)+"。\n":
		"You make a deep breath, stop using "+GONFU_NAME+" step!\n");
 
 	tell_room( environment(me),({
 		me->query("cap_name")+" makes a deep breath, stops using "+
 		GONFU_NAME+" step!\n", me->query("c_cap_name")+
 		"脚步逐渐缓慢, 终於停了下来。\n" }), me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}

#include <mudlib.h>

inherit DAEMON;

int enhant(object me, int level)
{
	int chinese_mode, db, fp;

	if( me->query_temp("scholar_booyi") ) {
		tell_object( me, 
			"你最好休息一下再运功。\n");
		return 0;
	}

	if( me->query("force_points") < (fp=30-random(level/2)) ) {
		tell_object( me,
			"你内力似乎不足以运出布衣神功。\n");
		return 0;
	}

	tell_object( me, 
		"你开始将内力聚於胸前并且开始运行护体布衣神功\。\n");
		
	tell_room( environment(me),sprintf("%s将双手合十一副心无旁骛的样子。\n",me->query("c_name")), me);
	db = 5 + level/3 + random(level/2);
	me->add("force_points", -fp);
	me->add("gonfus_exp/booyi", 2*level+1);
	me->set_temp("extra_db/booyi", db);
	me->set_temp("scholar_booyi", 1);
	call_out("release_booyi", 10+level+random(level), me, level);
	return 1;
}

varargs void release_booyi(object me, int level, int silent)
{
	if( !me ) return;
	if( !silent )
		tell_object( me,
			"你停止布衣神功\的运行 .... 。\n");
			
	me->delete_temp("extra_db/booyi");
	call_out("booyi_again", 40-level, me);
}

void booyi_again(object me)
{
	if( !me ) return;
	tell_object( me,		
	"你的内力又渐渐的回到丹田....\n");
	
	me->delete_temp("scholar_booyi");
}

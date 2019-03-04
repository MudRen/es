//#pragma save_binary
#include <mudlib.h>
inherit DAEMON;

int cmd_say(string str)
{
	if (!str) {
	write("你自言自语.\n");
	say( this_player()->query("c_name")+"自言自语的不知道在说什麽.\n");
	return 1;
	}
	printf( "你说道：%s\n",str);
	say( this_player()->query("c_name") + "说道：" + str + "\n");

	return 1;
}
 
int help()
{
	write ( @HELP
使用格式: say <信息>

说话，所有以你同一场景的人都可听见，有时是解谜的手段之一.
HELP
	);
	return 1 ;
}
//#pragma save_binary

/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_brief()
{
	int brief;
	brief = (int)previous_object()->query("brief");
	if(brief) {
		write("Verbose mode.\n");
		this_player()->set("brief", 0);
	} else {
		write("Brief mode.\n");
 		this_player()->set("brief", 1);
	}
	return 1;
}

int help()
{
	write ( @HELP
使用格式: brief

设定移动时所看到场景描述的详细程度.
如果对地区很熟悉或想加快网络速度，可以开启此功能.
HELP
	);
	return 1 ;
}

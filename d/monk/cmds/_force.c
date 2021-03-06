//#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

int help();

int cmd_force(string str)
{
	if( !str ) return help();
	if( !this_player()->query("max_fp") )
		return notify_fail("你有内力吗 ?\n");

	if( str == "on" ) {
		this_player()->set_temp("enable_inner_force", 1);
		write("你决定在战斗中消耗内力以增加战斗能力。\n");
		return 1;
	}   

	if( str == "off" ) {
		this_player()->delete_temp("enable_inner_force");
		write("你决定在战斗中不使用内力以节省你的内力消耗。\n");
		return 1;
	}
	return help();
}

int help()
{
write( @C_HELP
		
指令格式: force [on|off]
 
这个指令让你用来设定在战斗中是否消耗内力以增加战斗能力。

C_HELP
		);
    return 1;
}

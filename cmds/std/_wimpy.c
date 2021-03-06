//#pragma save_binary

/*
// The "wimpy" command.
// Coded by Buddha@TMI on 2/16/92
// Modified for 0.9.0 mudlib by Mobydick, 9/19/92
// This file is part of the TMI distribution mudlib.
// Please retain this header if you use it.
// added wimpydir together, less 1 command, by Kyoko@EasternStory.
*/

#include <mudlib.h>

inherit DAEMON;

int help();

mixed cmd_wimpy(string arg)
{
	int level, wimpy, set_wimpy = 0;
	string wimpydir;
	
	this_player()->block_attack(2);
	wimpy = (int)this_player()->query("wimpy");
	wimpydir = (string)this_player()->query("wimpydir");
	if( !wimpydir ) wimpydir = "random escape";
	
	if( !arg ) {
		write("Your wimpy is set to: "+wimpy+" HP, "+wimpydir+".\n");
		return 1;
	}

	if( sscanf(arg, "%d %s", level, wimpydir) == 2 ||
		sscanf(arg, "%s %d", wimpydir, level) == 2 ||
		sscanf(arg, "%d", level) == 1 )
		set_wimpy = 1;
	else if( sscanf(arg, "%s", wimpydir) == 1 )
		set_wimpy = 0;
	else return help();
	
	if( level > (int)this_player()->query("max_hp")*80/100 ) return notify_fail( 
		"你不能将逃跑的体力设超过你的最大体力的百分之八十。\n");
	if( set_wimpy && level >= 0 ) {
		this_player()->set("wimpy", level);
		wimpy = level;
	}
	
	if( !wimpydir || wimpydir == "none" || wimpydir == "random escape" )
		this_player()->delete("wimpydir");
	else if( wimpydir )
		this_player()->set("wimpydir", wimpydir);
		
	if( !wimpydir || wimpydir == "none" ) wimpydir = "random escape";
	printf("你现在设定体力低於 %d 会逃向 %s \n",wimpy,wimpydir);
	return 1;
}

int help()
{
   write(@HELP
使用格式: wimpy <逃跑值> <逃跑方向>
          wimpy <逃跑方向> <逃跑值>

设定当受攻击时如果体力值低于<逃跑值>时自动逃跑，
可以设定逃跑时的方向<逃跑方向>.

例子: wimpy 40, wimpy north,
      wimpy 40 north, wimpy north 40.
当你体力值低于40时自动朝北逃跑.
HELP
);
   return 1;
}

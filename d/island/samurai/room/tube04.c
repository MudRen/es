
#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下密室");
	set_long(@AAA
你来到一间地下密室，你开始确信这地下水道中一定有人居住，从
这房子的家具摆设来看，这个主人一定是个节俭的人，但你也感到奇怪
，为何这个人要躲到地下来住呢？在桌子旁有个奇怪的把手(lever) ．	
AAA
	);
        set("light",1);
	set( "c_item_desc", ([ 
		"lever" : @LONG_TEXT
这个把手你仔细观察之後，发现好像可以拉拉看(pull)
LONG_TEXT
 ]) );
	set( "exits", ([
		"south" : MR"tube03" ]));
	reset();
}

void init()
{
	add_action( "do_pull", "pull" );
}

int do_pull(string arg)
{
	if( !arg || arg!="lever" )
		return notify_fail( "你要拉啥呀?\n" );
	write("你一拉把手，墙壁就裂开一个开口，你随而进入墙壁里面\n"
		 );
	this_player()->move_player( MR"tube05", "SNEAK" );
	return 1;
}


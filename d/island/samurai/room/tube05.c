
#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("墙内密室");
	set_long(@AAA
这是一间墙壁内的密室，墙上挂了许多张地图，你仔细观看一下发现这
些地图是这附近区域的战力分布图，看来居住在此的人一定是武士团的重要
人物，不然他不可能拥有著这些机密资料．而其中有一张地图(map) 看起来
比其他的要来的旧，而且破损很多．	
AAA
	);
        set("light",1);
        set("objects",([
        "kola":MOB"kola"
        ]));
	set( "c_item_desc", ([ 
		"map" : @LONG_TEXT
这张地图你仔细观察之後，发现地图後面还有一个按钮(button)，似乎可
以按按看(push)
LONG_TEXT
 ]) );
	set("exits",([
	   "out":MR"tube04"
	   ]));
	reset();
}

void init()
{
	add_action( "do_push", "push" );
}

int do_push(string arg)
{
	if( !arg || arg!="button" )
		return notify_fail( "你是在练油压还是指压？手指到处乱按！\n" );
	write("你一按按钮，天花板就开了一个出口，你奋力一跳就跳出这间密室了\n"
		 );
	this_player()->move_player( MR"cac05", "SNEAK" );
	return 1;
}


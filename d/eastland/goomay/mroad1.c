// File: /d/eastland/goomay/mroad1.c
// Generated by Roommaker Thu Jan 27 01:46:44 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("古梅镇");
	set_long( @C_LONG_DESCRIPTION
这里是位於翰烟山下的一个小镇，三十来户的人家散布在一片方圆不到五里
的台地上，虽然如此，这个小镇的名字却是许\多人耳熟能详的，因为每年十月在
古梅镇所举行的武斗大会是所有身负绝艺的高手志在必得的盛会，优胜者可以得
十分丰富的赏赐与「东方第一勇士」的名衔，以及皇上御赐的「金丝甲」。
C_LONG_DESCRIPTION
	);

	set_outside( "goomay" );
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/eastland/2,4.east" ]) );
	reset();
#include <replace_room.h>
}

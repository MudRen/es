//#pragma save_binary

// translation done 2-21-94 -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("屋内");
	set_long( @C_LONG_DESCRIPTION
你现在进入了一间虽然小，但是十分明亮乾净的小屋，一张木制的
长方桌子，几只木制的椅子，显示这里的主人生活颇为简单，你可以看
到墙壁上挂著一些风乾的草药、植物、以及一些不知名的东西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"out" : "/d/noden/farwind/w_gate" ]) );
	set( "objects", ([ 
		"healer" : "/d/noden/farwind/monster/healer" ]) );
	reset();
#include <replace_room.h>
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#4" );
}
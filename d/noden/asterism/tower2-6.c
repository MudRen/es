// File: /d/noden/asterism/tower2-6.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的顶层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中矮人高塔的顶楼，也就是矮人王阿莱特斯四世的卧室，
房间中央一个大床，但是上面的寝具却和床不成比例。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"tower2-5",
		]) );
		
	set("objects",([
//          "king":MOB"dwarf_king",
	    "guard#1":MOB"dwarf_guard02",
	    "guard#2":MOB"dwarf_guard02",
	    ]) );
	reset();
}

void init()
{
   if( this_player() ) this_player()->set_explore("noden#35");
}

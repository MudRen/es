#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("屋子");
	set_long( @LONG
这里是羽民族小屋，平时羽民族住的地方。屋子有木制成的桌子、椅子和一张
床，以及一篓篓装满著刚采下来和晒乾的葡萄的大型篮子。小屋收拾的一尘不染，
虽然是些简单的摆设，对於生性不华丽的羽民族来说，已经足够了。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"village1" 
        ]) );
        set( "objects", ([
           "older#1" : SMOB"older1",
           "older#2" : SMOB"older1",
           "older#3" : SMOB"older1",
        ]) );
	reset();
}

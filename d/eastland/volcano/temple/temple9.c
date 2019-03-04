#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long( 
@LONG_DESCRIPTION
一条长长的走廊，你看到墙上有著壁画，是矮灵族中庆典时，乐人和舞者卖力
献技助兴的情形，大家围著广场中的营火尽情欢乐，裸体的是舞者，坐在一旁用手
拍打，或吹奏乐器的，都是乐人。往南可以通到正殿，往西可以到左殿，往北可通
往神殿深处。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : OTEMP"temple5",
     "west" : OTEMP"temple17",
     "north" : OTEMP"temple11",
     ]) );
reset();
#include <../replace_room.h>
}

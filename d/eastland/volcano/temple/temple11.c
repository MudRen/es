#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long(
@LONG_DESCRIPTION
一条长长的走廊，你看到墙上有著壁画，画著火山爆发时的景像，火山尘耸入
云霄，所有的飞禽鸟兽正四处奔窜。往南可以通到正殿，往北可通向神殿深处。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OTEMP"temple9",
     "north" : OTEMP"temple13",
     ]) );
reset();
#include <../replace_room.h>
}

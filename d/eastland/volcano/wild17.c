#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
这片空地崎岖不平，甚至有几条巨大的裂缝，把这块空地弄成看起来四分五裂的，
到处都是黑红色的石头，黑色的土壤，使你一看到这地型地物就知道一定是火山爆发後
的残留物，而且你觉得这里相当热，往东北方望去，果然不错，一座巨大的火山矗立在
那儿。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"varea1",
     "southeast" : ONEW"wild20",
     "southwest" : ONEW"wild18",
     "south" : ONEW"wild16",
     "northwest" : ONEW"wild14",
     ]) );
set( "objects", ([
     "mrat":OMONSTER"mrat" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

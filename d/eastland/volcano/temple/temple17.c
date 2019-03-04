#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿左殿");
	set_long(
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿左殿，神殿的顶端雕有火麒麟的图案，
这里供奉的是火麒麟，在矮灵族的传说中火麒麟是火神的坐骑之一。墙壁上有
著一幅壁画，描写矮灵族中欢乐的景象。坐在宴席上的贵宾，右侧是男女奴隶
，打扮的□丽非常，手拿著莲花伺候著；女奴头上戴有玉蜀黍状的饰物，正在
为客人倒酒。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple9",
     ]) );
set ( "objects", ([
      "l_enforcer":OMONSTER"l_enforcer",
      "wprayer":OMONSTER"wprayer"
      ]) );
set("light",1);
reset();
#include <../replace_room.h>
}

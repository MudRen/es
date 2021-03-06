#include "../oldcat.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("矮灵族神殿");
    set_long( 
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿正殿，正殿的顶端雕有火神的图案，一根
有龙纹的巨大柱子(post)竖在脚落，墙壁上雕满了许\多奇怪的花纹，地板是用一
块块的火山岩拼成的。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple1",
     "north": OTEMP"temple5",
     ]) );
set("item_desc",([
    "post" : @POST
一条栩栩如生的五爪红龙，全身是血红色的，一层层的鳞片闪闪发亮，两眼炯
炯有神的看著你。
POST
       ]));
set("light",1);
reset();
#include <../replace_room.h>
}

#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("灌木丛");
	set_long( 
@LONG_DESCRIPTION
你站在这片灌木丛中的小径上，树木的高度大约和你的身高差不多，以你的常
识判断，可能这个地区的水资源并不是那麽丰富，这条小径湮没在这参差不齐的灌
木丛之中，你发现在你旁边的地上有一滩血的遗迹，你猜你可能已经在猎头族的势
力范围内了，你还看到有一只小兔子躲在灌木丛里看著你。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "east" : ONEW"wild10",
     "northwest" : ONEW"wild7",
     "southwest" : ONEW"wild4", ]) );
set( "objects", ([
     "whunter":OMONSTER"whunter",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

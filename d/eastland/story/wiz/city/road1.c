#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("内殿甬道");
	set_long( @LONG
你正走在皇宫殿内的一条长数十尺的甬道上。这甬道雕梁画柱、瑶阶翠槛，珠
光宝气，耀眼生辉。两旁百盏琉璃莹灯，五花撩乱，全道通明，有如白昼；北边一
间偏室是铁扇公主的居所，通体碧玉砌成，金门翠东，富丽□皇，神仙宫室，不过
如斯。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "east" : SCITY"palace4",
          "north" : SCITY"house4"
        ]) );
        create_door( "north", "south", ([
          "keyword" : ({ "golden door", "door" }),
          "name" : "golden door",
          "c_name" : "金门",
          "c_desc" : "一个金澄澄的大门，上面各有两个雀环。\n",
          "status" : "closed"
        ]) );
	reset();
}

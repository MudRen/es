#include "goomay.h"

inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short( "大牢" );
        set_long(
@LONG
这里是捕快们关犯人的地方，犯了案的犯人都关在这里，一条简单的
长廊两旁都是牢房，当你走过时，牢里的犯人都用一种憎恶的眼光看著你
，甚至伸出枯\瘦的手来抓你。这里黑黝黝的，空气又差，你真想赶快出去。
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"jail",
                "west" : Goomay"police",
		"north" : Goomay"jail_room1",
		"south" : Goomay"jail_room2",
        ]) );
      create_door("west","east",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("north","south",
            ([  "keyword" : ({"north door","door"}),
                "name"    : "Iron door",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("south","north",
            ([  "keyword" : ({"south door","door"}),
                "name"    : "Iron door",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}


 
#include "hawk.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        set_short("ɽ´С��");
        set_light(1);
        set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
        );
        set( "exits", ([
        "north" : HAWK"room2-11",
	"south" : HAWK"room2-13",
                     ]) );
    reset();
}//end of creat
 

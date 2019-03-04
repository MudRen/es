#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
      set_short( "书斋" );
	set_long(
             "这是一间给人读书的房间，在房中间放着一张书桌，桌上杂乱无章，\n"
     "到处都是书本。\n"
	);
        set( "light",1 );
        set( "exits", ([
 "down" : "/u/s/sage/test/pet_shop",
  "up" : "/d/wiz/wiz_hall",
    "east" : "/u/s/sage/work.c"
        ]) );
}

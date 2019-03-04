#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草地上的小路");
	set_long( @LONG
你正站在一条玉制小路上，小路向东边方向延伸，四周是绿草如茵，西边有一
玉制平台。草地上各色繁花，花大如钱，偶一阵微风吹过，花随同披佛，漫天花香，
清馨醒脑，沁人心脾，犹还染濡衣襟，沾了一身香气。
LONG
	);
	set("light",1);
        set( "exits", ([
            "plate" : SPALACE"plain1",
             "east" : SPALACE"plain3"
        ]) );
	reset();
}

// File: /d/noden/asterism/ladder02.c

#include "asterism.h"


inherit ROOM;

void create()
{
	::create();
	set_short("通往山顶的石梯");
	set_long( 
		@C_LONG_DESCRIPTION
一座巨大的山峰耸立在你的面前,在贝尔基山脉的主峰,阿莱特山的
面前,你感觉到你是如此的渺小.你已经很接近艾斯特律恩城了,有个巨大
的告示板(board)被立在这里。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
        "board":"----------------------------------------------------------------\n"
                "      矮人王阿莱特斯,地精长老埃乙尔,半身人族长席蓝洛斯          \n"
                " 三人共同立碑与此,後代的子孙必须谨守下列的誓言..................\n"
                " 矮人族,地精族,与半身人将永远和平共处於艾斯特律恩城中,共同抵抗外\n"
                " 来的侵掠,不得相互交战於城内.                                   \n"
                "                      ---於最後一次地精--魔族对抗战争後一年.    \n"
                "----------------------------------------------------------------\n"    
          ]) );        

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"city_entrance", 
		"down" : ASTR"ladder02", 
		]) );
	reset();
#include "replace_room.h"
}

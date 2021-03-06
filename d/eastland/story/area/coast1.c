#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("沙滩");
	set_long( @LONG
你现在来到了一处平坦的白沙滩，西边是一望无际的大海，头顶是炙热的□阳
和一抹无垠的青空。波浪慢条斯理地拍打著沙岸，溅起些许水花；海风徐徐轻拂著
你的脸颊，吹散了周遭炙窒的热气，四肢百骇彷佛感受到它的恩惠，扫尽了酷署的
日照；沙滩上各式贝类星罗棋布或游走著小螃蟹；海里头穿梭著五彩斑斓的鱼儿。
徜徉在这一片白沙滩里，顿时感到烦恼尽失，使你不再想到任何杀伐争执。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast2",
        ]) );
	reset();
}

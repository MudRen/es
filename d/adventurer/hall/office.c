#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
   ::create();
   set_short( "小办公室" );
   
   set_long(@CLONG
这是冒险者公会中一个不起眼的小办公室，听说很多冒险的资料都放在这个房
间，房间的角落有一张书桌( table)，书桌旁有两张皮椅。旁边放著几盆观叶
植物，为这个阴暗的角落增添一股生气。
CLONG);
	set( "light",1 );
	set("c_item_desc",(["table":
"这张桌子上堆满了许多的文件，但由於经过细心的整理，不但没有杂乱的感觉， \n"
"反而另有一种壮观的美感。桌上还放著一盏小巧的油灯，昏黄的灯光，使这间房间\n"
"多了一种古老但却温暖的感觉。油灯旁还有一个小香炉，正冒出缕缕的青烟。\n"	

	                   ,"censer":
"一个古色古香的小香炉，炉里的香气让你想起古老的东方．\n"	

	]));
        set( "exits", ([
                "south" : "/d/adventurer/hall/adv_libra1",
                ]) );
                
         set("no_monster",1);
         
         set("objects",(["officer" : "/d/adventurer/hall/monsters/sophia"]));
         
         create_door("south","north",([
                     "keyword":({"woodendoor","door"}),
                     "status":"closed",
                     "c_desc":"一个小小的木门",
                     "c_name":"小木门",
                     "name":"small wooden door",
                     "desc":"a small wooden door",
                                     ]) );
         reset();                     
}

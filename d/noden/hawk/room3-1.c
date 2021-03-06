#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("市政大厅二楼");
        set("light",1);
        set_long( @LONG_DESCRIPTION
这里是天空之城行政中心，装璜的富丽堂皇，可表现出鸟人族高人一等的建
筑技术，墙上挂满了历代鸟人族领袖的肖像(photos)。往北可以通到长老的办公
室，往南，则是鸟人族领袖办公的地方。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "north" : HAWK"room3-2",
                "west" : HAWK"room3-3",
                "down" : HAWK"room2-14",
                "south" : HAWK"room3-6",
                "east" : HAWK"room3-7",
                        ]) );
        set( "objects",([
                "prayer" : MOB"god2",
                        ]) );
        create_door("west","east",([
                "keyword":({"black door","door"}),
                "status":"closed",
                "c_desc":"一个黑色的门",
                "c_name":"黑玉门",
                "name":"black jade door",
                "desc":"a black jade door",
                        ]) );

        create_door("east","west",([
                "keyword":({"white door","door"}),
                "status":"closed",
                "c_desc":"一个白色的门",
                "c_name":"白玉门",
                "name":"white jade door",
                "desc":"a white jade door",
                        ]) );
        set("c_item_desc",([
		"photos":" 你看到一张张历代鸟人族英雄的肖象，一个个威风凛凛。\n",
                        ]) );
    reset();
}//end of creat


int clean_up()
{

      return 0;
}


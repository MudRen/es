// translation done. -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("入口");
	set_long( @C_LONG_DESCRIPTION
你站在古老建筑物(house)的大门前, 生锈虚掩的铁门被风吹得嘎嘎做响, 这里寒
风刺骨, 风出奇的强, 藤蔓爬满了墙壁, 越发觉得此处的可怕。门口站著两只石像鬼
, 似乎在警告你别进去。
C_LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([
		"south" : MOYADA"mainrd6",
	]) );
	set( "item_desc", ([
      "house" : "一栋古老而破旧的房子, 你胆子够大的话, 也许能进去(enter)瞧瞧.\n"
	]) );
	set( "objects", ([
	  "gargoyle#1" : MOYADA"monster/gargoyle",
	  "gargoyle#2" : MOYADA"monster/gargoyle",
	]) );
	reset();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
   if( this_player() ) this_player()->set_explore("noden#8");
	write( "一阵莫明的恐惧让你放弃这念头!\n" );
	return 1;
}

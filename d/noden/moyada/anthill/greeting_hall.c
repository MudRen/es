#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("招待室");
	set_long( @C_LONG_DESCRIPTION
这里看起来像是这些怪蚁们接待客人的地方，你很怀疑它们会有什麽客人?
也许是其他国度的蚁类吧。奇怪的桌子上放著一些面包 (bread)和乳酪(butter)
，好像可以吃的样子。桌子旁坐著几只奇怪的红色蚂蚁。
C_LONG_DESCRIPTION
	);
	set( "item_desc", ([
      "bread" : "一些吃剩的面包，看起来似乎可以吃。\n",
      "butter" : "已经发酵了的乳酪，闻起来臭臭的。\n",
    ]) );
	set( "exits", ([
		"south" : MOYADA"anthill/cellar1",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant waiter" : MOYADA"monster/ant_waiter",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",5);
}

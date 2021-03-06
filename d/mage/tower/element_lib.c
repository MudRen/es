//#pragma save_binary
#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "元素魔法图书室");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你现在来到银色之塔中藏书最丰富的一间图书室，这里所收藏有关元素魔法的
经典和书籍是任何地方也比不上的，除了目前魔法师们广为使用的几种魔法之外，
有些书籍上所记载的法术到现在还没有人能看懂，你可以翻阅第一个书架上的索引
(index)，看看目前有哪些法术可以参考，往西是通往图书馆大厅的通道。
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"west" : MAGE"library" ]) );
	set( "item_func", ([
	    "index" : "view_catalog" ]) );
	set_spells( ([
		"light"       : ({ "elemental", 10, 7, 10, 100 }),
		"fireball"    : ({ "elemental", 15, 6, 10, 150 }),
		"sleet"       : ({ "elemental", 40, 4, 10, 150 }),
    "flamming-shield" : ({ "elemental", 40, 3, 15, 115 }),
      "ice-shield"    : ({ "elemental", 40, 3, 15, 135 }),
	]) );
	reset();
}


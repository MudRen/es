//#pragma save_binary
#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
        ::create();
        set_short("A white room", "白魔法图书室");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
你现在来到银色之塔中藏书最丰富的一间图书室，这里所收藏有关白魔法的
经典和书籍是任何地方也比不上的，除了目前魔法师们广为使用的几种魔法
之外，有些书籍上所记载的法术到现在还没有人能看懂，你可以翻阅第一个
书架上的索引(index)，看看目前有哪些法术可以参考,往西是通往图书馆大
厅的通道。
C_LONG_DESCRIPTION
        );
    set( "no_monster", 1);
        set( "light", 1 );
        set( "exits", ([ 
                "east" : MAGE"library" ]) );
        set( "item_func", ([
            "index" : "view_catalog" ]) );
        set_spells( ([
                "antidote"       : ({ "white-magic", 40, 4, 15, 150 }),
                "heal"    : ({ "white-magic", 40, 4, 15, 150 }),
                "paralyze"       : ({ "white-magic", 40, 4, 15, 150 }),
    "power-boost" : ({ "white-magic", 40, 4, 15, 150 }),
      "protect"    : ({ "white-magic", 40, 4, 15, 150 }),
        ]) );
        reset();
}

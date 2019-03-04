#include "mercury.h"

inherit MONSTER ;
inherit SELLER  ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "fruit merchant","水果贩" );
        add ("id", ({ "merchant"}) );
        set_short( "fruit merchant","水果贩");
        set("unit","位");
        set_long(@ANGEL
这是一个卖水果的小贩，你可以问他关於价钱(price)的事
ANGEL
        );
        set_inventory( ({
        ({MIT"orange", 20, 20 }),
        ({MIT"apple", 15, 15 }),
        ({MIT"lemon", 10, 10 })
        }));
        set("inquiry",([
              "price":"@@show_menu"
              ]));
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
}

void init()
{
	npc::init();
	seller::init();
}
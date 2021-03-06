#include <mudlib.h>
inherit SELLER;
inherit ROOM;

void create()
{
	::create();
    set_short("秘密的军火贩卖处");
	set_long( @LONG_DESCRIPTION
你现在来到一家新开的走私店，整齐的柜台上排放著许\多的用品，绷带， 装备
、药水、应有尽有，你看到门口的柜台上钉著一张价目表(menu)，你有预感这家
药材店会是你常常光顾的地方。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([
 		"island":"/d/island/7,2.island",
		"drow":"/d/noden/drow/r04",
		"south" : "/u/s/smore/home/home" ]) );
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set_inventory( ({
		({ "/obj/bandage", 60, 60 }),
		({ "/d/healer/potion/black_plaster", 30, 30 }),
		({ "/d/deathland/object/blueapple.c", 30, 30 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/tomb/item/great_pill", 20, 20 }),
		({ "/d/knight/fortress/weapons/dragonblood", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_plate", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_leggings", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_gauntlets", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_shield", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_boots", 3, 3 }),
		({ "/d/knight/fortress/armors/silver_helmet", 3, 3 }),
		({ "/d/eastland/goomay/obj/travel_bag", 3, 3 }),
		({ "/d/eastland/volcano/weapon/sword1", 3, 3 }),
		({ "d/island/weapon/jousting", 3, 3 }),
		({ "d/island/hole/weapon/axe1", 3, 3 }),
		({ "d/island/hole/weapon/scale_sword", 3, 3 }),
		({ "/d/island/hole/armor/plate3", 3, 3 }),
		({ "/d/island/hole/armor/arms5", 3, 3 }),
		({ "/d/island/hole/armor/shield7", 3, 3 }),
		({ "/d/island/hole/armor/tail3", 3, 3 }),
		
	}) );

        set( "objects", ([
                "guard#2" : "/d/noden/nodania/monster/palace_guard",
                "guard#1" : "/d/noden/nodania/monster/palace_guard",
                "vendor"  : "/obj/vendor",
   		 ]) );
	reset();
}
	void reset()

{
	room::reset();
	seller::reset();
}

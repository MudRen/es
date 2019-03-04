#include <mudlib.h>
inherit SELLER;
inherit ROOM;

void create()
{
	::create();
    set_short("���ܵľ�������");
	set_long( @LONG_DESCRIPTION
����������һ���¿�����˽�꣬����Ĺ�̨���ŷ�����\�����Ʒ�������� װ��
��ҩˮ��Ӧ�о��У��㿴���ſڵĹ�̨�϶���һ�ż�Ŀ��(menu)������Ԥ�����
ҩ�ĵ�����㳣����˵ĵط���
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

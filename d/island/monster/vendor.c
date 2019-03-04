#include "../island.h"

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "vendor", "������̯��" );
	set("id",({"vendor"}));
	set_short( "������̯��" );
	set_long(@LONG
��������ض��еĵ�̯С����������������Ǳ���ĵط����صص�����̯��
����������й�(item)���£��������������Щʲ�ᡣ
LONG
	);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "pie", 30 );
	set_perm_stat( "kar", 30 );
	set_skill( "tactic" , 100 );
	set_skill( "dodge" , 100 );
	set_skill( "parry" , 100 );
	set_skill( "unarmed" , 100 );	
	set ("max_hp", 1000 );
	set ("hit_points", 1000 );
	set_natural_weapon( 80 , 25 , 60 );
	set_natural_armor( 90 , 30 );
	set( "race", "lizardman" );
	set( "tactic","assault" );
	set( "gender", "male" );
	
	set_inventory( ({
		({ "/obj/torch", 25, 25 }),
		({ "/obj/map",   20,20  }),
		({ "/obj/bandage",30,30 }),
		({ "/obj/bag",10,10}),
	}) );
	set( "inquiry", ([
		"item" : "@@show_menu"
	]) );
	set( "shop_name", "vendor" );
}

void init()
{
	npc::init();
	seller::init();
}

#include <mudlib.h>


inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "̯��" );
	set_short( "̯��" );
	set_long(
		"һ�������������Ƶ�̯�������������Ҫ�Ļ�����������������Ʒ��ֻҪ\n"
		"������Ǯ(price)�����ͻ����㿴���Ļ��\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 }),
                ({ "/d/eastland/beggar/item/bag", 3, 3}), 
                ({ "/d/eastland/beggar/item/sausage", 10 , 10 }) 
   	}) );
	set( "inquiry", ([
		"price" : "@@show_menu"
	]) );
}
void init()
{
	npc::init();
	seller::init();
}


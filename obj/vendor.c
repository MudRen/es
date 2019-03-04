#include <mudlib.h>


inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "С��" );
	set_short( "С��" );
	set_long(
		"һ�������������Ƶ�С�������������Ҫ�Ļ�����������������Ʒ��ֻҪ\n"
		"������Ǯ(price)�����ͻ����㿴���Ļ��\n"
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 })
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
#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "С��" );
	set_short( "С��" );
	set_long(@C_LONG
һ�������������Ƶ�С�������������Ҫ�Ļ�����������������Ʒ��ֻҪ
������Ǯ(price)�����ͻ����㿴���Ļ��
C_LONG
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set( "shop_name", "vendor");
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 })
	}) );
	set( "inquiry", ([
		"price" : "@@show_menu"
	]) );
}

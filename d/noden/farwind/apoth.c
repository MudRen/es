//#pragma save_binary

//translation done. 2-21-94 what about menu? hmm..  -Elon

#include <mudlib.h>
inherit SELLER;
inherit ROOM;

void create()
{
	::create();
    set_short("����ҩ�ĵ�");
	set_long( @LONG_DESCRIPTION
����������һ���¿���ҩ�ĵ꣬����Ĺ�̨���ŷ������ҽ�Ƶ���Ʒ������
��ҩˮ��Ӧ�о��У��㿴���ſڵĹ�̨�϶���һ�ż�Ŀ��(menu)������Ԥ�����
ҩ�ĵ�����㳣����˵ĵط���
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/noden/farwind/wbazz" ]) );
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set_inventory( ({
		({ "/obj/bandage", 60, 60 }),
		({ "/d/noden/farwind/items/branz_herb", 50, 50 }),
		({ "/d/noden/farwind/items/plaster", 40, 40 }),
		({ "/d/noden/farwind/items/white_plaster", 30, 30 }),
		({ "/d/noden/farwind/items/mikira_potion", 30, 30 }),
		({ "/d/noden/farwind/items/kira_potion", 30, 30 }),
		({ "/d/noden/farwind/items/makira_potion", 20, 20 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}

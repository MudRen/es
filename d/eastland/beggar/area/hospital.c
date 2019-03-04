#include "../dony.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("ҩ��");
	set_long( @C_LONG
��һ�߽����ҩ�̾��ŵ�һ��ҩ��ζ�� �����ǡ�н���塻Ψһ��һ�ҿ���ҽ
�Ƶ�ҩ�� ,����Сѩ�Ӿ�ͨҽ��,�����������Ķ���Ҳ����, ���еĶ�����ȫд��
һ�Ź��ڱ��ϵĻ���(paper)�ϡ�����Կ�����������������Ҫ�ġ�
C_LONG
	);
	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"up":DBEGGAR"hospital1.c",
		"east":DBEGGAR"north1.c"
		       ]) );
	
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}

// File: /d/eastland/easta/herb_shop.c
// Generated by Roommaker Thu Jan 27 11:07:31 1994

#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("��ͩ��ҩ��");
	set_long( @C_LONG_DESCRIPTION
��һ�߽����ҩ�̣����ŵ�һ��Ũ����̴�㣬��������ᰳ���ʷ���ϵ�һ��ҩ
�̣���Ѱ���ĵ���ҩ�࣬���ѵ�һ����ǧ���ϡ������ﶼ�У����ҩ�̻���һ����
���ĵ���ҩ�䷽��������������ࡹ�������������ޱȣ�����������ҩ�����Ǯ��
д��һ�Ź��ڱ��ϵĻ���(paper)�ϣ������������ϴ�ֵĶ���ͬ��
C_LONG_DESCRIPTION
	);

	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"east" : "/d/eastland/easta/south_ealley" ]) );
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
                ({ "/d/eastland/easta/obj/plaster1", 40, 40 }),
                ({ "/d/eastland/easta/obj/white_plaster1", 40, 40 }),
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
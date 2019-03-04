#include "../island.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("��ͩ��ҩ�̷ֺ�");
	set_long( @C_LONG_DESCRIPTION
��һ�߽����ҩ�̣����ŵ�һ��Ũ����̴�㣬��������ᰳ���ʷ����
����ͩ��ҩ���ڴ������ķֺš���Ѱ���ĵ���ҩ�࣬���ѵ�һ����ǧ����
�Σ����ﶼ�У����ҩ�̻���һ���洫�ĵ���ҩ�䷽��������������ࡹ
�������������ޱȣ�����������ҩ�����Ǯ��д��һ�Ź��ڱ��ϵľ���
(paper)�ϡ�
C_LONG_DESCRIPTION
	);

	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"east" : ITOWN"town06" ]) );
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/eastland/easta/obj/plaster", 40, 40 }),
		({ "/d/eastland/easta/obj/white_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 20, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
		({ IOBJ"paste",20,20 }),
	}) );
	reset();
}
void reset()
{
      seller::reset();
      room::reset();
      return;
}

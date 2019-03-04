#include "../../story.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("ҩ��");
	set_long( @C_LONG
��һ�߽����ҩ����ŵ�һ�ɴ̱ǵ�ҩ��ζ�������ǡ����̳ǡ���Ψһ��һ��
�Ϸ�ҩ�꣬ר����Щҩ���������׵Ĺ��������������Ķ�������Ҳû���˻�ȥ��
�ۻ��۵ģ����еĶ�����ȫд��һ�Ź��ڱ��ϵĵ���(menu)������Կ�����������
����Ҫ�Ķ�����
C_LONG
	);
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"west":SCITY"ws"
		       ]) );
	
	set( "objects", ([
	       "doctor":SWMOB"wiz_doctor1",
            "patient#1":SWMOB"patient1", 
            "patient#2":SWMOB"patient1",
            "patient#3":SWMOB"patient1",
	]) );
	set_inventory( ({
		({ "/obj/bandage",60,20 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 20 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 30 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 20 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 15 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}

#include "ekravia.h"
inherit SELLER;
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("ħ����");
	set_long(@Long
����һ������������յ�С��, һƬ�����н��й�̨ǰ��һ��ż��©
��һ�����⡣��̨�����ƺ�û�˿���, �����е㲻֪���롣���ù�̨����
����һ���嵥 (list)��
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"south"		: HERE"tinker_way2",
		]) );
	set_inventory( ({ 
		({ "/d/noden/moyada/obj/wands/flamming_wand", 5, 5 }),
		({ OBJ"firework", 5, 5 }),
		({ OBJ"chain_fw", 2, 1 }),
		}) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
�㿴��һ�ŷ��Ƶ�ֽ��, ����д��:
LIST
	);
	::show_menu();
}

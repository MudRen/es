#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("Сҩ��");
	set_long(@Long
���߽�һ��Сҩ�ꡣ�谵��С�ռ���, ����ҩ�ĵ���ζ�ڿ���Ʈ����
��һ����ʢ����֪��ҩ���Сƿ�ӻ����Ƽ���������������̨, ��������
����ƾ�����С���ϵ�һ�ǽ������Լ���������Χ��
    �ò��������ڹ�̨��һ��, ����ҩƿ�Ŀ�϶���ҵ���������Ҫ��ҩƷ
�嵥 (list)��
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way3",
		]) );
	set("objects", ([
		"alchemist"	: MOB"alchemist",
		]) );
	set_inventory( ({ 
		({ OBJ"potions/inca_potion", 50, 50 }),
		({ OBJ"potions/green_potion", 30, 30 }),
		({ OBJ"potions/vigor_potion", 30, 30 }),
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

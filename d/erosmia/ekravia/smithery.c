#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("������");
	set_long(@Long
���߽�������, ���ô���������ֱ�������������������Դ���Է�
��һ�ǵ����衣�ȵò����˵Ĺķ�¯�������Բ�Զ��������������ط�ɢ
�ҷ���һЩ���ߡ�
    ǽ�Ϲ�����������, ��Ŷ�������Ĳ�Ʒ�������·�����һЩ����,
�����Ա߶���һ��ľ��(sign)
Long
);

	set("item_func", ([
		"sign"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way4",
		]) );

	set_inventory( ({ 
		({ OBJ"longsword", 5, 5 }),
		({ OBJ"dagger", 3, 3 }),
		({ OBJ"chainmail", 5, 5 }),
		}) );
		
	set("objects", ([
		"smith"	: MOB"smith",
		]) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
�㿴��һ��ֲڵ�ľ��, �������:
LIST
	);
	::show_menu();
}

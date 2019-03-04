#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	base_room::create();
	set_light(1);
	set_short("���־ư�");
	set_long(@CLong
���߽�һ�Ҿưɡ�Բ�����߽��Ρ��Ʊ�����̸���۵���������еľ�
��ζ��һͬ������������Ŀռ䡣�Ʊ� (barkeeper) �����İ�̨ (bar)
�����ڷ����һ��, �����˿�����ǰ�档
CLong
);

	set("c_item_desc", ([
		"bar"		: @ITEM_BAR
���߽���̨, �����������һ���˵� (Menu)�� 
ITEM_BAR
		, "menu"	: @ITEM_MENU
����һ����ͨ�Ĳ˵�, �������ϸ���� (read) ����
ITEM_MENU
	]) );

	set("exits", ([
		"east"		: HERE"corridor1",
	]));
	
	set( "objects", ([
		"barkeeper" :	MOB"barkeeper",
	]) );
	
	set_inventory( ({
		({ OBJ"potions/rum", 20, 20 }),
	}) );
	reset();
}

void	init()
{
	seller::init();
	base_room::init();
	add_action( "read_menu", "read" );
}

int	read_menu(string s)
{
	if (!s) return 0;
	if (s = lower_case(s) != "menu")	return 0;
	write ( @MENU_MSG
�㷭���˵�ϸ��, ����д��
MENU_MSG
	);
	show_menu();
	
	return 1;
}
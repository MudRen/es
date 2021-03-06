#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	base_room::create();
	set_light(1);
	set_short("枫林酒吧");
	set_long(@CLong
你走进一家酒吧。圆桌、高脚椅、酒杯、高谈阔论的人与空气中的酒
精味道一同混杂於这个不大的空间。酒保 (barkeeper) 与他的吧台 (bar)
隐藏在房间的一角, 几个顾客坐在前面。
CLong
);

	set("c_item_desc", ([
		"bar"		: @ITEM_BAR
你走近吧台, 发现上面放了一本菜单 (Menu)。 
ITEM_BAR
		, "menu"	: @ITEM_MENU
这是一本普通的菜单, 你可以仔细读读 (read) 它。
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
你翻开菜单细读, 上面写著
MENU_MSG
	);
	show_menu();
	
	return 1;
}
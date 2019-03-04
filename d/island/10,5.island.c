// File: 10,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @LONG_DESCRIPTION
����һƬ�ɸ������Ƶľ�ľ�����ɵ������������ľ���ܣ���ʹ�㼸
���������������ʲ����ڣ�Ҳ����������ǰ���кܶ����صĴ�˵��
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"9,5.island", 
		"north" : ISLAND"10,4.island", 
		"east"  : ISLAND"11,5.island",
		"south" : ISLAND"10,6.island",
		]) );
	set( "original", ISLAND"10,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 5 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}


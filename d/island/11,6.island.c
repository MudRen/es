// File: 11,6.island.c

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
		"west"  : ISLAND"10,6.island", 
		"north" : ISLAND"11,5.island", 
		"east"  : ISLAND"12,6.island",
		"south" : ISLAND"11,7.island",
		]) );
	set( "original", ISLAND"11,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 6 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}


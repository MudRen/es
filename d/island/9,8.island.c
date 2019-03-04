// File: 9,8.island.c

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
		"west"  : ISLAND"8,8.island", 
		"north" : ISLAND"9,7.island", 
		"east"  : ISLAND"10,8.island",
		"south" : ISLAND"9,9.island",
		]) );
	set( "original", ISLAND"9,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}


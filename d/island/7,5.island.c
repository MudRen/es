// File: 7,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("����С��");
	set_long( @LONG_DESCRIPTION
�����������һ����е�����С����·�ϲ��������������һ������µ�
���������ö����������������Ե��һ��֣�ʹ�����������������ܣ���
С����Ȼ���Ǻ�ֱ�����Ǵ����ϻ�������������ġ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
	        "west"  : ISLAND"6,5.island",
		"north" : ISLAND"7,4.island",
		"east"  : ISLAND"8,5.island", 
		"south" : ISLAND"7,6.island",
		]) );
	set( "original", ISLAND"7,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}

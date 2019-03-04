// File: 7,3.island.c

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
С��һ·�ɴ�������������ʧ�ˣ��������������һ��֣���ͬ���Ǻ���
����Щ����Щ�Ź֣���ȥ���ưɣ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,3.island", 
		"north" : ISLAND"7,2.island", 
		"east"  : ISLAND"8,3.island",
		"south" : ISLAND"7,4.island",
		]) );
	set( "original", ISLAND"7,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 3 );
	reset();
#include <replace_room.h>
}

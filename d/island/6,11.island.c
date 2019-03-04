// File: 6,11.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @LONG_DESCRIPTION
���������г��˲���ֲ�������ԭ��������ˮ�ĵ��棬Ҳ��һЩ��
��ֲ������ˣ����������Ӧ��ע����棬������������ӣ��޷��԰Ρ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,11.island", 
		"north" : ISLAND"6,10.island", 
		"east"  : ISLAND"7,11.island",
		"south" : ISLAND"6,12.island",
		]) );
	set( "original", ISLAND"6,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 11 );
	reset();
#include <replace_room.h>
}

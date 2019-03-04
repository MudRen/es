// File: 8,9.island.c

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
		"west"  : ISLAND"7,9.island", 
		"north" : ISLAND"8,8.island", 
		"east"  : ISLAND"9,9.island",
		"south" : ISLAND"8,10.island",
		]) );
	set( "original", ISLAND"8,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 9 );
	reset();
#include <replace_room.h>
}


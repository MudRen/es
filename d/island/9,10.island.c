// File: 9,10.island.c

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
		"west"  : ISLAND"8,10.island", 
		"north" : ISLAND"9,9.island", 
		"east"  : ISLAND"10,10.island",
		"south" : ISLAND"9,11.island",
		]) );
	set( "original", ISLAND"9,10" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 10 );
	reset();
#include <replace_room.h>
}


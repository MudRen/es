// File: 12,8.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("��̲");
	set_long( @LONG_DESCRIPTION
�⺣̲��ɳ���ǻƽ�ɫ�ģ�����֮�⣬������ɳ�е�ʯӢ�ʣ����ϵ�
�������ߣ�һ�����ģ���ε�������ϵ����㲨�⣬��ӳ��Ȥ��	
LONG_DESCRIPTION
	);
        
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"11,8.island", 
		"east"  : ISLAND"13,8.island",
		"south" : ISLAND"12,9.island",
		]) );
	set( "original", ISLAND"12,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 12 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}

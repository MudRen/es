// File: 9,11.island.c

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
		"west"  : ISLAND"8,11.island", 
		"north" : ISLAND"9,10.island", 
		"east"  : ISLAND"10,11.island",
		"south" : ISLAND"9,12.island",
		]) );
	set( "original", ISLAND"9,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 11 );
	reset();
#include <replace_room.h>
}

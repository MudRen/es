// File: 2,8.island.c

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
		"west"  : ISLAND"1,8.island", 
		"south" : ISLAND"2,9.island", 
		"east"  : ISLAND"3,8.island",
		]) );
	set( "original", ISLAND"2,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 2 );
	set( "y_coordinate", 8 );
        set( "no_monster", 1 );
	reset();
}

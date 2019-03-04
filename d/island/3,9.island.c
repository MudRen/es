// File: 3,9.island.c

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
		"west"  : ISLAND"2,9.island", 
		"north" : ISLAND"3,8.island", 
		"east"  : ISLAND"4,9.island",
		"south" : ISLAND"3,10.island",
		]) );
	set( "original", ISLAND"3,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 3 );
	set( "y_coordinate", 9 );
        set( "no_monster", 1 );
	reset();
}

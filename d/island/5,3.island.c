// File: 5,3.island.c

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
		"west"  : ISLAND"4,3.island", 
		"north" : ISLAND"5,2.island", 
		"east"  : ISLAND"6,3.island",
		"south" : ISLAND"5,4.island",
		]) );
	set( "original", ISLAND"5,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 3 );
        set( "no_monster", 1 );
        set( "objects" ,([
                 "c1":IMON"crow"
                 ]));
	reset();
}

// File: 9,3.island.c

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
		"west"  : ISLAND"8,3.island", 
		"north" : ISLAND"9,2.island", 
		"east"  : ISLAND"10,3.island",
		"south" : ISLAND"9,4.island",
		]) );
	set( "original", ISLAND"9,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 3 );
        set( "no_monster", 1 );
        set( "objects", ([
                 "t1":IMON"turtle2",
                 "t2":IMON"turtle3"
                 ]));
	reset();
}

// File: 12,6.island.c

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
		"west"  : ISLAND"11,6.island", 
		"north" : ISLAND"12,5.island", 
		"east"  : ISLAND"13,6.island",
		]) );
	set( "original", ISLAND"12,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 12 );
	set( "y_coordinate", 6 );
        set( "no_monster", 1 );
        set( "objects",([
                 "t1":IMON"turtle",
                 "t2":IMON"turtle1"
                 ]));
	reset();
}

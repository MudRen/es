// File: 4,4.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("Ϫ��");
	set_long( @LONG_DESCRIPTION
СϪ��������͵����ˣ������Ҳ����������ˣ�����Ҫ�ر�С��
������Ȼ�������������Ҫ�ö��ˡ�
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"3,4.island", 
		"north" : ISLAND"4,3.island", 
		"east"  : ISLAND"5,4.island",
		"south" : ISLAND"4,5.island",
		]) );
	set( "original", ISLAND"4,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 4 );
	set( "y_coordinate", 4 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 4, 1 );
}

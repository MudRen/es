// File: 10,10.island.c

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
		"west"  : ISLAND"9,10.island", 
		"north" : ISLAND"10,9.island", 
		"east"  : ISLAND"11,10.island",
		"south" : ISLAND"10,11.island",
		]) );
	set( "original", ISLAND"10,10" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 10 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 4, 1 );
}

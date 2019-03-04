// File: 8,11.island.c

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
		"west"  : ISLAND"7,11.island", 
		"north" : ISLAND"8,10.island", 
		"east"  : ISLAND"9,11.island",
		"south" : ISLAND"8,12.island",
		]) );
	set( "original", ISLAND"8,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 11 );
        set( "no_monster" , 1 );
        set( "objects" , ([
                    "lizard":IMON"lizardman"
                    ]));
	reset();
#include <replace_room.h>
}


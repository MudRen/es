// File: 7,11.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("«έ���");
	set_long( @LONG_DESCRIPTION
����������·�Ǻܲ����׵ģ�����������˺÷�������ʯͷ�Բ�����
ס��Ȼ�����������У�����������ֲ«έ���Ա���·������������·����
���������������˵�����Ҫ���������ˣ����·���������ͨ��һ����
ʯƽ̨���Ƕ������������˶�Ѩ����ڣ�������Ӧ��С�ĵ�ࡣ������˲�
�����ǰ���
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,11.island", 
		"north" : ISLAND"7,10.island", 
		"east"  : ISLAND"8,11.island",
		"south" : ISLAND"7,12.island",
		]) );
	set( "original", ISLAND"7,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 11 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}


// File: 7,9.island.c

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
���������������˵�����Ҫ���������ˣ��ⲻ�����۵��Ǻ�ʵ�õĵ�·
���ϱ���ģ���ͨ�������˵ľ�������������ҪС�ı���·�Ū���ˡ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,9.island", 
		"north" : ISLAND"7,8.island", 
		"east"  : ISLAND"8,9.island",
		"south" : ISLAND"7,10.island",
		]) );
	set( "original", ISLAND"7,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 9 );
	reset();
#include <replace_room.h>
}

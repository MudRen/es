// File: 8,4.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�һ���");
	set_long( @LONG_DESCRIPTION
������һƬ�������һ����У�����������ν�ġ���Ӣ�ͷף�������
������Ҫ����ϸ�۲�˴�����������ᷢ��������ĳ������Ĵ���������
�������ֿ���������������ĺۼ��������ǻ�Ȼ��ɵİɣ�������վ��Խ
�ã���Խ������������������Ѿ�����Զȥ�������Ŀ������ĸо���ʹ��
���������������	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"7,4.island", 
		"north" : ISLAND"8,3.island", 
		"east"  : ISLAND"9,4.island",
		"south" : ISLAND"8,5.island",
		]) );
	set( "original", ISLAND"8,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 4 );
	reset();
#include <replace_room.h>
}

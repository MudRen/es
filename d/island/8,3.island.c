// File: 8,3.island.c

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
		"west"  : ISLAND"7,3.island", 
		"north" : ISLAND"8,2.island", 
		"east"  : ISLAND"9,3.island",
		"south" : ISLAND"8,4.island",
		]) );
	set( "original", ISLAND"8,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 3 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

// File: 6,5.island.c

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
		"west"  : ISLAND"5,5.island", 
		"north" : ISLAND"6,4.island", 
		"east"  : ISLAND"7,5.island",
		"south" : ISLAND"6,6.island",
		]) );
	set( "original", ISLAND"6,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 5 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

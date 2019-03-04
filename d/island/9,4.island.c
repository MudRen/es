// File: 9,4.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�һ���");
	set_long( @LONG_DESCRIPTION
������һƬ�������һ����У�����������ν�ġ���Ӣ�ͷף�������
������Ҫ����ϸ�۲�˴�����������ᷢ��������ĳ�����صĴ���������
�������ֿ���������������ĺۼ��������ǻ�Ȼ��ɵİɣ�������վ��Խ
�ã���Խ������������������Ѿ�����Զȥ�������Ŀ������ĸо���ʹ��
����������������ϱߺͶ�������С�ӣ������е��С��ࡣ�	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,4.island", 
		"north" : ISLAND"9,3.island", 
		"east"  : ISLAND"10,4.island",
		"south" : ISLAND"9,5.island",
		]) );
	set( "original", ISLAND"9,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 4 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

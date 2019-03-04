// File: 5,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�����");
	set_long( @LONG_DESCRIPTION
��������������֮�еĵ�·����ʵҲ���ǿ����̳����ģ�����������
��������̤��һ��С·��·�����߳����ģ��⻰������û����С·��
������ģ�ͨ����ʿ����
LONG_DESCRIPTION
	);


	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,7.island", 
		"north" : ISLAND"5,6.island", 
		"east"  : ISLAND"6,7.island",
		"south" : ISLAND"5,8.island",
		]) );
	set( "original", ISLAND"5,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

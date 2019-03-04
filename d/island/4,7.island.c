// File: 4,7.island.c

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
		"west"  : ISLAND"3,7.island", 
		"north" : ISLAND"4,6.island", 
		"east"  : ISLAND"5,7.island",
		"south" : ISLAND"4,8.island",
		]) );
	set( "original", ISLAND"4,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 4 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}


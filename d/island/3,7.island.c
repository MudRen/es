// File: 3,7.island.c

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
������ģ�����͵�Ŀ�ĵ��ˣ��������ߵ��Ǻ�ΰ����ʿ�������ȥ�ɣ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : "/d/island/samurai/room/station", 
		"north" : ISLAND"3,6.island", 
		"east"  : ISLAND"4,7.island",
		"south" : ISLAND"3,8.island",
		]) );
	set( "original", ISLAND"3,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 3 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}


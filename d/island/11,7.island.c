// File: 11,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�����");
	set_long( @LONG_DESCRIPTION
��λ��ɭ���еĵ�·��ħ������ģ���ʯ���̳ɵ�·�棬��ֱ������
���д��������Ե���ľ���ð������˵���������������ʮ����ˬ������
�����������������ͣ�ˣ��������и�С�������������гǱ������ӣ�
����Ҫ��������Ҫ��һ�������ˣ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"10,7.island", 
		"north" : ISLAND"11,6.island", 
		"east"  : "/d/island/forest/area/start",
		"south" : ISLAND"11,8.island",
		]) );
	set( "original", ISLAND"11,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

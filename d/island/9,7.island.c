// File: 9,7.island.c

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
����������������ӳ����ͽ����ǡ�
LONG_DESCRIPTION
	);



	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,7.island", 
		"north" : ISLAND"9,6.island", 
		"east"  : ISLAND"10,7.island",
		"south" : ISLAND"9,8.island",
		]) );
	set( "original", ISLAND"9,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 7 );
	reset();
#include <replace_room.h>
}

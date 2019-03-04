// File: 5,8.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("С����");
	set_long( @LONG_DESCRIPTION
���������������ϳ��������̵��ʲݣ�����׺���ϵ�С�׻���ʹ��
�����˾��þ�����죬վ��������Կ���Զ���Ĵ󺣣�������Ϊ���ﶼû
�иߴ��ֲ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,8.island", 
		"north" : ISLAND"5,7.island", 
		"east"  : ISLAND"6,8.island",
		"south" : ISLAND"5,9.island",
		]) );
	set( "original", ISLAND"5,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}
// File: 5,5.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("СϪ");
	set_long( @LONG_DESCRIPTION
�����㻹���ܲ������峺��ˮ���ٻ���������������ʮ�����õ��£�
����Ҫע�������£���һ�������˻������ڶ�����Ȼ������ˮ��ץ�㣬��
����Ⱦ����ร���СϪһ·��������ȥ��
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,5.island", 
		"north" : ISLAND"5,4.island", 
		"east"  : ISLAND"6,5.island",
		"south" : ISLAND"5,6.island",
		]) );
	set( "original", ISLAND"5,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 5 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}

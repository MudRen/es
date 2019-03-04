// File: 8,6.island.c

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
		"north" : ISLAND"8,5.island", 
		"east"  : ISLAND"9,6.island",
		]) );
	set( "original", ISLAND"8,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 6 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}

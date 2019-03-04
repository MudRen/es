// File: 9,9.island.c

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
		"west"  : ISLAND"8,9.island", 
		"north" : ISLAND"9,8.island", 
		"east"  : ISLAND"10,9.island",
		"south" : ISLAND"9,10.island",
		]) );
	set( "original", ISLAND"9,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 9 );
	reset();
	
}

void init()
{
  UNDERWATER -> apply_effect( this_player(),7,1);
}
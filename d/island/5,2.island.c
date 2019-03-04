// File: 5,2.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("ǳ��");
	set_long( @LONG_DESCRIPTION
����ǿ������ߵĵ�ǳ������Ȼ��ǳ��һ��������10�������ڣ�����
��Σ�յģ���ʱҪע���Լ�������״������ҪӲ�ţ�ࡣ����ˣ��������
��������С�Ŀ��ܻᱻ��ú�Զ��
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"east"  : ISLAND"6,2.island",
		"south" : ISLAND"5,3.island",
		]) );
	set( "original", ISLAND"5,2" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 2 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}

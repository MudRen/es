// File: 10,11.island.c

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
		"west"  : ISLAND"9,11.island",
		"north" : ISLAND"10,10.island",
		]) );
	set( "original", ISLAND"10,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 11 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
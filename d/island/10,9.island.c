// File: 10,9.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @LONG_DESCRIPTION
����һƬ�ɸ������Ƶľ�ľ�����ɵ������������ľ���ܣ���ʹ�㼸
���������������ʲ����ڣ�Ҳ����������ǰ���кܶ����صĴ�˵��
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"9,9.island", 
		"north" : ISLAND"10,8.island", 
		"east"  : ISLAND"11,9.island",
		"south" : ISLAND"10,10.island",
		]) );
	set( "original", ISLAND"10,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 9 );
        set( "objects",([
                "s1":IMON"squirrel",
                "s2":IMON"squirrel",
                "s3":IMON"squirrel"
                 ]));
	reset();
}

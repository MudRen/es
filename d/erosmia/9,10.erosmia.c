
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ɽ��С��" );
	set_long( @LONG_DESCRIPTION
�����ڵͰ���ɽ����, ��Χ�������Ĳ�ԭ�뻨�䡣������ɽ���¿���
����һ�������ĳ��򡣴��Ǳ�, һ��С�����Ѷ���, ��������ǰ, ����
���ߵ�ɽ�С�
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/9,9.erosmia", 
		"east"	: "/d/erosmia/ekravia/west_gate", 
//		"west"	: "/d/erosmia/8,10.erosmia",
		"south"	: "/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/9,10" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 10 );
	reset();
}

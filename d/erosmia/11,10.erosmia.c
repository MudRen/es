
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��·" );
	set_long( @LONG_DESCRIPTION
������������һ����ʯ�̳ɵĵ�·�ϣ���·�򶫡����������졣·�ԵĲ�
���ϳ���һЩ��֪����Ұ����Ұ�ݡ�
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/11,9.erosmia", 
		"east"	: "/d/erosmia/12,10.erosmia", 
		"west"	: "/d/erosmia/ekravia/east_gate",
		"south"	: "/d/erosmia/11,11.erosmia",
		]) );
	set( "original", "d/erosmia/10,11" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 10 );
	reset();
}


#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ƽԭ" );
	set_long( @LONG_DESCRIPTION
����������һƬƽ���ϣ��������ݵ�׺��һЩ��ʯ�����￪������
Ұʹ���������ؿ���Զ���ľ��
    �ϱ߲�Զ�����Կ���һ�������ĳ���, һ���Ͱ���Χǽ������������
����û��·����ǰ���ǳ���
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/10,8.erosmia", 
		"east"	: "/d/erosmia/11,9.erosmia", 
		"west"	: "/d/erosmia/9,9.erosmia",
		]) );
	set( "original", "d/erosmia/10,9" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 9 );
	reset();
}


#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("On the Plain", "��Ұ");
	set_long( @C_LONG_DESCRIPTION
��վ��һ���޼ʵ���Ұ��, ������������С����紵���������,
����һ������ɫ�Ĳ��ˡ����ߵ�Զ��, һ�������ĳ������ŵ�б���ɽ��
�ԡ�������������ϱ߲�Զ��, ���������Ĵ�ӡ�
C_LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north" : "/d/erosmia/ekravia/south_gate", 
		"east" : "/d/erosmia/11,11.erosmia", 
		"west"	:"/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/10,11" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 11 );
	reset();
}

#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����ͨ��");
	set_long( 
@C_LONG_DESCRIPTION
�����һ��������ͨ�������ܼ���ذ������㼸�����������Լ��������ͽŲ������Ӧ
������ǰ������һ�����ĺ��⣬����������δ���й��ĸо����㲻����ԥ���������׸ò���
������ǰ����??
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/square13", 
		"west" : TOMB"/sword2",  ]) );
	reset();	
#include <replace_room.h>
}


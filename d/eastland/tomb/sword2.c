#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����ͨ��");
	set_long( 
@C_LONG_DESCRIPTION
�����һ��������ͨ�������ܼ���ذ������㼸�����������Լ��������ͽŲ������Ӧ
������ǰ�������ĺ���Խ��Խ�أ�����������δ���й��ĸо����㲻����ԥ���������׸ò�
�ü�����ǰ����??
C_LONG_DESCRIPTION
	);
	
	set( "exits", ([ 
		"east"  : TOMB"/sword1",
		"west"  : TOMB"/sword3"  ]) );
	reset();
#include <replace_room.h>
}


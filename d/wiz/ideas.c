#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������" );
	set_long(
			"����ط�������Щ���µ��ӣ����ǲ�֪�����Ὣ��ʵ������������\n"
		"û��ʱ��д����ʦ���ṩ������ʦ���ӵĵط������������������Լ�\n"
		"Ҫ���ģ�������������( �����߾��� )��\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/planning"
	]) );

	// Cause the idea_board to load
	call_other( "/d/wiz/idea_board", "???" );
}

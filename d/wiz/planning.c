#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����" );
	set_long(
			"��������ʦ�����󻮵ĵط��������������ĳ���󻮣�ϣ��������\n"
		"ʦ��æ���ṩ����ģ���������������( �����ǹ�� )����������ʦ��\n"
		"�������ģ��������Իص���ʦ�칫�ҡ�\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/wiz_office",
		"west"	:	"/d/wiz/ideas"
	]) );

	// Cause the plan_board to load
	call_other( "/d/wiz/plan_board", "???" );
}

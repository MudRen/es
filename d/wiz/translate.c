#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��Ӣ�ķ�����" );
	set_long(
			"��춶�������ͬʱ֧Ԯ������Ӣ���������ԣ���������ĳ�ʽ�б�\n"
		"��ͬʱ�ṩ�������Ե�ѶϢ���������ڷ�����Ǽӽ���������Ϥ������\n"
		"ѶϢ�������ѣ�����������������������ʦ��æ���������Իص�Ʒ�ʹ�\n"
		"�Ʋ���\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/qc-request"
	]) );

	// Cause the trans_board to load
	call_other( "/d/wiz/trans_board", "???" );
}

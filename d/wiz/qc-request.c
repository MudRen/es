#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "Ʒ�ʹ��Ʋ�" );
	set_long(
			"��������ʦ������Ʒ�ʹ��Ʋ�������Ҫ��������ҽӴ��õ�����\n"
		"����Ʒ�����뾭��Ʒ�ʹ��Ʋ�����ˡ�����Ҫ����Ʒ�ʼ��������\n"
		"( ��ʽ����� \"help policy\" )д����������԰��ϣ�����ʦ�ǻ�\n"
		"���������˲����������������㶫�ߵ�����Ӣ�ķ����ҡ�\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/wiz_office",
		"east"	:	"/d/wiz/translate"
	]) );

	// Cause the QC-request board to load
	call_other( "/d/wiz/qc_board", "???" );
}

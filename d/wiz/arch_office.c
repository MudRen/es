#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����ʦ�칫��" );
	set_long(
			"�����Ǵ���ʦ�ǰ칫�ĵط�������ո����ľ������������ڷ��䣬��\n"
		"���� ... �ƺ��������ʦ�칫�Ҳ�ࡣ������������ ���������з���\n"
		"���ϱ���һ���������ܲ����۵�ľ�ţ��������һ������(sign)��\n"
	);
	set( "item_desc", ([
		"sign" : "The sign reads: \"God Office\".\n"
	]) );

	set( "c_item_desc", ([
		"sign" : "������д��: ��İ칫�ң�����Ī�롣\n"
	]) );

	set( "light", 1 );

	set( "exits", ([
		"north"	:	"/d/wiz/wiz_office",
		"west"	:	"/d/wiz/RandD"
	]) );

	// Cause the arch_board to load
	call_other( "/d/wiz/arch_board", "???" );
}
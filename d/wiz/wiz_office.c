#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��ʦ�칫��" );
	set_long( @LONG
������Ȼ����ʦ�ǰ칫�ĵط���������ʦ��ƽ���󲿷ݶ�����
�Լ��Ĺ����ҡ�������Ҫ��������һЩ��ʦ�����԰塢����( ���
 )�ȣ���������ʦ�����������Ƚ�ǡ����
    ����������Իص���ʦ��������������������ң�������Ʒ
�ܲ������ϣ����Ǵ���ʦ�İ칫�ҡ�
LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"north"	:	"/d/wiz/wiz_hall",
		"south"	:	"/d/wiz/arch_office",
		"west"	:	"/d/wiz/planning",
		"east"	:	"/d/wiz/qc-request"
	]) );

	// Cause the wizard board to load
	call_other( "/d/wiz/wiz_board", "???" );
}

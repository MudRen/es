#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("���¹㳡");
	set_long( 
@C_LONG_DESCRIPTION
�����һ���޴�Ĺ㳡���ھ������᳤�õ�·���ᣬ��������л�Ȼ���ʵĸо���ʵ��
�޷�������Ĺ�����������ڵص��½�����˴�Ĺ㳡���㲻������Щ�������˷־��⡣
�㳡�Ͽտյ����ģ��ƺ�û���κ�������ڣ�Ҳ��\��\�������ˡ�������Զ��������ʲ�ᶫ��
�����Ĺ��������ȥ̽��������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square6", 
		"south" : TOMB"/square4",
		"east"  : TOMB"/lin1",
		"west"  : TOMB"/square18"  ]) );
	reset();	
#include <replace_room.h>
}


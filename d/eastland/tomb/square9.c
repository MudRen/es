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
�㳡�Ͽտյ����ģ��ƺ�û���κ�������ڣ�Ҳ��\��\�������ˡ����ϱ�Զ��������ʲ�ᶫ��
�����Ĺ��������ȥ̽��������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : TOMB"/square19",
		"east"  : TOMB"/square8",
		"west"  : TOMB"/square10"  ]) );
	reset();	
}

void init()
{
	if ( this_player()->query_temp("ORB_POOL") )
		add( "exits", ([ "down" : TOMB"/down1" ]) );
}

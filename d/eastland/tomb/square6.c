#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("���¹㳡");
	set_long( 
@C_LONG_DESCRIPTION
��......�����һ���޴�Ĺ㳡���ھ������᳤�õ�·���ᣬ��������л�Ȼ���ʵĸ�
����ʵ���޷�������Ĺ�����������ڵص��½�����˴�Ĺ㳡���㲻������Щ��������
�־��⡣�㳡�Ͽտյ����ģ��ƺ�û���κ�������ڣ�Ҳ��\��\�������ˡ��㿴�������ƺ���
��Ѱ���Ķ�����
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north"  : TOMB"/square7",
		"south"  : TOMB"/square5"  ]) );
	reset();	
#include <replace_room.h>
}

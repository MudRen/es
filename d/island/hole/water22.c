
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����ʯ��Ѩ" );
	set_long(@LONG
���Ȼ����һ����ʪ�Ķ�Ѩ���������˵�ˮ���ɶ�Ѩ�������
��̧ͷһ���������������ߵ�����ʯ�ϣ���Ȼ���¼���������ˮ���
�������ϡ�ɲʱ��������ݷ������ɾ���	
LONG
		);
	set( "exits",([ 
			"north" : HOLE"water21",
			"southwest" : HOLE"water23",
		]) );
	reset();
	
}
#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "���¶�Ѩ" );
	set_long(@LONG
һ��������ĵ��¶�Ѩ����������������˷����������㲻ͣ
�Ĳ�����Ȼ�����㾲��������ʱ��������������ˮ�����ڷ���֮��
���ڰ�֮�У�����Լ�����ƺ���˫̰�����۾����ڴ������㡣�㲻��
����߽��ģ�������ʱ�����޴Ӷ�Ѩ�ܳ�����
LONG
		);
	set( "exits",([
			"southwest" : HOLE"hole10",
			]) );
	set( "objects",([ "bat" : HMONSTER"vampire01" ]) );
	reset();
#include <replace_room.h>	
}
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
			"up" : "/d/island/7,12.island.c",
			"north" : HOLE"hole01",
			"south" : HOLE"hole03",
		]) );
	reset();
#include <replace_room.h>	
}

#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������" );
	set_long(@LONG
��������վ�ĵ�λ���������������ĵڶ��㣬�������ῴ������
�Ǹ���ٹ��˵���Ϣ������������˵�Ǹ���Ѩ��Ϊǡ��������������
Ϊ�����������ͱȽϲ�������ס��������ɵġ�
LONG
	);
	set( "exits",([
			"south" : HOLE"hole40",
			"north" : HOLE"hole44",
			"west" : HOLE"hole41",
			"east" : HOLE"hole43",
			]) );
	reset();
#include <replace_room.h>
}

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
			"up" : HOLE"hole38",
			"north" : HOLE"hole42",
			]) );
	reset();
#include <replace_room.h>
}

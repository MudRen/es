#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������" );
	set_long(@LONG
��������վ�ĵ�λ���������������ĵ�һ�㣬�������ῴ������
�Ǹ���ٹ��˵���Ϣ������������˵�Ǹ���Ѩ��Ϊǡ��������������
Ϊ�����������ͱȽϲ�������ס��������ɵġ�
LONG
	);
	set( "exits",([
			"down" : HOLE"hole40",
			"northwest" : HOLE"hole36",
			]) );
	reset();
#include <replace_room.h>
}

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
			"northwest" : HOLE"hole35",
			"northeast" : HOLE"hole37",
			"southwest" : HOLE"hole39",
			"southeast" : HOLE"hole38",
			]) );
	reset();
#include <replace_room.h>
}

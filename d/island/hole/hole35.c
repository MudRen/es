#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�������" );
	set_long(@LONG
�����ڵ�λ������������������ڣ��������ῴ�������Ǹ����
���˵���Ϣ������������˵�Ǹ���Ѩ��Ϊǡ��������������Ϊ������
�����ͱȽϲ�������ס��������ɵġ������������ƺ�����Ϊ��ĵ�
������߽䱸��
LONG
	);
	set( "exits",([
			"up" : HOLE"hole34",
			"southeast" : HOLE"hole36",
			]) );
	set( "objects",([
			"lifeguard#1" : HMONSTER"life_guard",
			"lifeguard#2" : HMONSTER"life_guard"
			]) );
	reset();
#include <replace_room.h>
}

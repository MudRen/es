#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "��̦�㳡" );
	set_long(@LONG
��Ѩ������ƺ���ÿ������ˣ�����ǽ���Ϲ��������ѣ�ʹ����
������Ŀ��������ʯ���е�һ�С�Ŷ������ԭ�������������ƽʱ��
��Ĺ㳡�����ʯ���ϳ����˵���ɫ����̦���ʵ�������̦�㳡����
LONG
		);
	set( "light",1 );
	set( "exits",([
			"east"  : HOLE"hole24",
			"south" : HOLE"hole22",
			"north" : HOLE"hole20"
			]) );
	reset();
#include <replace_room.h>
}
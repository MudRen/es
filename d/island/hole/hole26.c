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
			"west"  : HOLE"hole23",
			"south" : HOLE"hole27",
			"northeast" : HOLE"hole29" 
			]) );
	reset();
#include <replace_room.h>
}
#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "����" );
	set_long(@LONG
������޴�Ķ�Ѩ�У���Ȼ����һ��С�������ڱ߻����������ʯ��
Ŷ���������ˣ�ԭ������������˵���վ��ƽʱ�����������ڴ�פ���Է�
ֹ��ʿ����ħ��ľ��ӣ������������µ�����û�͵Ϯ��	
LONG
		);
	set( "exits",([
			"northeast" : HOLE"hole30",
			"southwest" : HOLE"hole26"
			]) );
	set("objects",([
			"guard#2" : HMONSTER"sentry",
			"guard#1" : HMONSTER"sentry"
			]) );
	reset();
#include <replace_room.h>
}

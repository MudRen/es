#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "����" );
	set_long(@LONG
������޴�Ķ�Ѩ�У���Ȼ����һ��С�������ڱ߻����������ʯ��
Ŷ���������ˣ�ԭ������������˵���վ��ƽʱ�����������ڴ�פ���Է�
ֹ��ʿ����ħ��ľ��ӣ������������µ�����û�͵Ϯ������������ر�
�ƺ��������ط�ɭ��Ү!	
LONG
		);
	set( "exits",([
			"north" : HOLE"hole25",
			"southeast" : HOLE"hole32"
			]) );
	set( "objects",([
			"guard#2" : HMONSTER"sentry",
			"guard#1" : HMONSTER"sentry"
			]) );
	reset();
#include <replace_room.h>
}

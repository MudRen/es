#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����ͨ��");
	set_long(
@C_LONG_DESCRIPTION
����������һ�������ĵ���ͨ�������ܵ�ǽ�������Ϻ�ʯש���ɵģ����ϻ���һ��ǳǳ
�Ļң��ƺ��Ѿ��к�һ��ʱ��û���˽�������ͨ�������һ�������磬��ľ��������
�������ʮ����ֵľ��������δ֪��Σ�ա�
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/maze8",
		"west" : TOMB"/maze6",
		"north" : TOMB"/maze6", 
		"south" : TOMB"/maze6" ]) );
	reset();
#include <replace_room.h>
}


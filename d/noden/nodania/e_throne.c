#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set( "light", 1 );
	set_short( "����" );
	set_long(@CLONG
�����������е�һ�����ȣ�����������ǹ������������������ǹ���
��ͼ���ҡ�һ�����ξ�����¥��ͨ��������¥��
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"throne_room",
		"east" : NODANIA"royal_lib",
		"up" : NODANIA"upstair_1"
	]) );
	create_door( "east", "west", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "��ľ��",
		"status" : "locked",
		"c_desc" : "һ�ȵ��λ�������ľ�ţ���\n",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
}

#include "nodania.h"

inherit ROOM;

void create()
{
	object king;

	::create();
	set( "light", 1 );
	set_short( "������" );
	set_long(@CLONG
�������˹���Ү����ʮһ����������������ƽ����������ʹ���
���ֹ��£��������Ĳ��úʹ�����࣬�����������Ա������űȽ�С
�����Σ��ֱ��ǻʺ��С��������λ���ϱ��������Ĵ��������ߵĻ���
ͨ��������ͼ��ݣ��������ǻʺ���ղ��ҡ�
CLONG
	);
	set( "exits", ([
		"south" : NODANIA"palace_hall",
		"west" : NODANIA"collection",
		"east" : NODANIA"e_throne"
	]) );
	set( "objects", ([
		"body guard#1" : NODANIA"monster/body_guard",
		"body guard#2" : NODANIA"monster/body_guard",
	]) );
	king = new(NODANIA"monster/yaramon_xi");
	king->move(this_object());

	reset();
}

int clean_up() { return 0; }

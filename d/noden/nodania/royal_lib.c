#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	seteuid(getuid());
	set( "light", 1 );
	set_short( "������ͼ����" );
	set_long(@CLONG
�������˹���Ү����ʮһ����ר��ͼ���ң�����Ĳ�����Ȼ����ŵ
�����Ǵ�ͼ��ݷḻ����Ҳ��Ӧ�о��С�����Դӹ�������е��鼮��
�෢��Ү����ʮһ�����й�ֲ������ر�����Ȥ��
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"e_throne"
	]) );
	create_door( "west", "east", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "��ľ��",
		"c_desc" : "һ���λ�������ľ�š�\n",
		"status" : "locked",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
/*
	set( "objects", ([
		"Annihilator": "/adm/gods/annihilator" ,
		"Kyoko": "/adm/gods/kyoko",
		"Layuter": "/adm/gods/layuter",
		"Echobomber": "adm/gods/echobomber", ]) );
*/
	reset();
}

void clean_up() { return 0; }

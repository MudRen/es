#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("a farmer's house", "ũ��");
	set_long(@CLong
���߽�һ��ũ��, �����ſڵĹ㳡�ϼ�ֻѼ�����������յ��л�����
һ�����������ſ�, ����������㳡��ľ�ɫ��
CLong
);
	set("exits", ([
		"south"		: HERE"small_road2"
		]));
	set( "objects", ([
		"oldman": MOB"old_man",
		"duck1"	: MOB"duck",
		"duck2"	: MOB"duck",
	]) );
	reset();
}

#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("end of a small road","С·��ͷ");
	set_long(@CLong
С·��������ֹ, ���ߵĹ�԰��ס��ȥ·��һ��ũ�Ҿ���С·����,
����Կ���ũ���ſڵĿյ��ϼ�ֻ��Ѽ���е�������ȥ��
CLong
);
	set("exits", ([
		"east"		: HERE"small_road1",
		"north"		: HERE"farmer_house"
		]));
	set( "objects", ([
		"goose1"	: MOB"goose",
		"goose2"	: MOB"goose",
	]) );
	reset();
}

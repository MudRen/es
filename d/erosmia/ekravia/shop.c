#include "ekravia.h"
inherit SHOP;

void	create()
{
	::create();
	set_light(1);
	set_short("shop","�̵�");
	set_long(@Long
������ר���������չ���������ð��װ�����ӻ���, �������������
��������ð����������������װ������\�ഫ˵�е��������������������
����ֹ�, ���в��ٵĴ�������Ǵ�����̵꿪ʼ�ġ�
Long
);
	set("exits", ([
		"east"		: HERE"maple_street4",
	]));
	set("objects", ([
		"trashcan"	: "/obj/trashcan",
	]) );
	reset();		                                                                        
}

#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("purple platemail","��������ս��");
    add("id",({"plate","platemail"}) );
    set_short( "purple platemail","��������ս��");
	set_long(
		"This is a platemail with beautiful marks....\n",
		"����һ��������ս�ף���ǰ������������ͼ���������Ŀ����������\n"
		"��ӵ�������˱ض��Ǹ�����Ʒζ���ˣ�\n"
	);
	set( "unit", "��" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 153, "gold" }) );
}

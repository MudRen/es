#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("green chainmail","����Ż�ս��");
    add("id",({"chainmail","mail"}) );
    set_short( "green chainmail","����Ż�ս��");
	set_long(
		"This is a suit of green chainmail \n",
		"����һ�������͵ġ��ף���֪������ʲ������Ƴɵģ���ǰ��\n"
		"��\���������廨ͼ����\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 290, "gold" }) );
}

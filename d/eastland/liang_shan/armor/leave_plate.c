#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron platemail","��Ҷ����");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","��Ҷ����");
	set_long(
		"This is a plate called iron platemail....\n",
		"���������ϸ�ܵ���Ҷ����ϳɵ�ս�ף�����˵���Ƿ��߲������\n"
		"Ϊ����Ʒ���������������˸о�ۼȻһ��\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 6 );
	set( "value", ({ 251, "gold" }) );
}

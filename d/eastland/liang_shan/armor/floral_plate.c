#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("floral platemail","÷����Ҷ��");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","÷����Ҷ��");
	set_long(
		"This is a plate called floral platemail....\n",
		"���������ϸ�ܵ���Ҷ����ϳɵ�ս�ף�����˵���Ƿ��߲������\n"
		"Ϊ����Ʒ������Ҷ�䣬��׺�����÷���͵���Ʒ��\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 36 );
        set("material","light_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 253, "gold" }) );
}

#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Dragon plate","����������");
    add("id",({"plate","dragon"}) );
    set_short( "dragon plate","����������");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"����һ����������ľ���ս�ף�������һ�޴�����ƣ��ƺ���\n"
		"�Ż���������������һ�㺮�����֣���������ƺ������������\n"
	);
	set( "unit", "��" );
	set( "weight", 666 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 10 );
	set( "value", ({ 666, "gold" }) );
        set( "special_defense",(["ire":15,"evil":10]));
                                    
}

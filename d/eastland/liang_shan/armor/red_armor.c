#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("red armor","����");
    add("id",({"armor"}) );
    set_short( "red armor","����");
	set_long(
		"This is a red armor for warriors. \n",
		"һ������ս�ף�����Ʒ�ʻ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 75 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","light_metal");
	set( "defense_bonus", 3 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":4,"poison":1]));
}

#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("white armor","�׼�");
    add("id",({"armor"}) );
    set_short( "white armor","�׼�");
	set_long(
		"This is a white armor for warriors. \n",
		"һ��ѩ�׵�ս�ף�����Ʒ�ʻ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","light_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":3,"poison":1]));
}

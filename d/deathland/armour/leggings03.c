#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy leggings", "��ʥ�ּ�");
        add( "id", ({"leggings" }) );
        set_short("a pair of holy leggings", "��ʥ�ּ�");
        set_long(
                "A pair of leggings enchanted holy power.\n",
                "һ˫������ʥ�������ּ�\n"
        );
        set( "unit", "˫");
        set( "type", "legs" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine":5, "none":-3 ]) );
        set( "weight", 140 );
        set( "value", ({ 2000, "silver" }) );
}

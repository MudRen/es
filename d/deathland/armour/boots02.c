#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril boots", "������սѥ");
        add( "id", ({ "boots" }) );
        set_short("a pair of mithril boots", "������սѥ");
        set_long(
                "A pair of boots made of mithril .\n",
                "һ˫�������������ɵ�սѥ\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "light_metal" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 1450, "silver" }) );
}

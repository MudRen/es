#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril black boots", "�������Ь");
        add( "id", ({ "boots" }) );
        set_short("a pair of mithril black boots", "�������Ь");
        set_long(
                "A pair of boots made of mithril and iron  .\n",
                "һ˫�����������������϶��ɵ�Ь��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "weight", 80 );
        set( "value", ({ 770, "silver" }) );
}

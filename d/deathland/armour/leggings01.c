#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril leggings", "�������ּ�");
        add( "id", ({"leggings" }) );
        set_short("a pair of mithril and silver leggings", "���������ּ�");
        set_long(
                "A pair of leggings made of mithril and silver.\n",
                "һ˫�����������������ɵ��ּ�\n"
        );
        set( "unit", "˫");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 150 );
        set( "value", ({ 950, "silver" }) );
}

#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black mithril leggings", "��ɫ������ϥ");
        add( "id", ({"leggings" }) );
        set_short("a pair of black mithril leggings", "��ɫ������ϥ");
        set_long(
                "A pair of leggings made of mithril and some mystic metal.\n",
                "һ˫����������ĳ�����صĽ�����ɵ��ֻ�ϥ\n"
        );
       // set("no_sale",1);
        set( "unit", "˫");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 100 );
        set( "value", ({ 5700, "silver" }) );
}

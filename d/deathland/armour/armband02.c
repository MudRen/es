#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silver armband", "���ۻ�");
        add( "id", ({"armband" }) );
        set_short("a silver armband", "���ۻ�");
        set_long(
                "An armband used by last dwarven guard.\n",
                "һ�����ۻ�,���൱�õķ�����\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "heavy_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 40);
        set( "value", ({ 770, "silver" }) );
}

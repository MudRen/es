#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("dwarven armband", "���˱ۻ�");
        add( "id", ({"armband" }) );
        set_short("a dwarven armband", "���˱ۻ�");
        set_long(
                "An armband used by dwarf.\n",
                "һ������ר�õıۻ�\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "light_metal" );
        set( "armor_class", 2 );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 720, "silver" }) );
}

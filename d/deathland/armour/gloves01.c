#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silk gloves", "˿������");
        add( "id", ({"gloves" }) );
        set_short("a silk gloves", "˿������");
        set_long(
                "An gloves made of silk.\n",
                "һ˫˿������,������������ʹ�ø�������\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
        set( "defense_bonus", 2 );
        set( "extra_skills", ([ "parry":3 ]) );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}

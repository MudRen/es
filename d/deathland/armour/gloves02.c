#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("gloves of power", "��������");
        add( "id", ({"gloves" }) );
        set_short("a pair of gloves of power", "��������");
        set_long(
                "An gloves of power.\n",
                "һ˫ǿ������,��������Ӷ�������������\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "material", "heavy_metal" );
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "weight", 55 );
        set("extra_stats",([ "str":1 ]));
        set( "value", ({ 4000, "silver" }) );
}

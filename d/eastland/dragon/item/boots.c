#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("golden boots", "黄金鞋");
        add( "id", ({ "boot","boots" }) );
        set_short("黄金鞋");
        set_long(
                "这是一双用纯金打造的鞋\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "weight", 100 );
        set( "value", ({ 150, "gold" }) );
}

#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail of elf", "精灵铠甲");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "精灵铠甲" );
        set_long(
                "这是精灵王用特殊的金属加上大神扬小邪的祝福所制成的铠甲，甲\n"
                "上有著精灵的的标帜。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "light_metal");
        set( "armor_class", 30 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "poison":-1 ]) );
        set("no_sale",1);
        set( "weight", 200 );
        set( "value", ({ 400, "gold" }) );
}

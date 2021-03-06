#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven cloak", "精灵披风");
        add( "id", ({ "cloak" }) );
        set_short( "精灵披风" );
        set_long(
                "这是精灵王用独角兽皮加上精灵族特殊的秘方所烘制成的披风 \n"
                "，穿起来既舒适又耐用，相信会给你的身体带来极大的保护。\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-2 ]) );
        set( "weight", 80 );
        set( "value", ({ 1200, "silver" }) );
}

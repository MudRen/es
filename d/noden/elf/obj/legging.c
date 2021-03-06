#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven leggings", "精灵胫甲");
        add( "id", ({ "leggings" }) );
        set_short( "精灵胫甲" );
        set_long(
                "这是精灵王用独角兽皮加上精灵族特殊的秘方所烘制成的胫甲 \n"
                "，穿起来既舒适又耐用，相信会给你的腿带来极大的保护。\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":8, "evil":-5, "fire":-2 ]) );
        set( "weight", 40 );
        set( "value", ({ 100, "gold" }) );
}

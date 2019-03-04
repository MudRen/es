#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_chainmail", "武士铠甲");
        add( "id", ({ "chainmail" }) );
        set_short("samurai_chainmail", "武士铠甲");
        set_long(@AAA
一个低等级武士所穿的铠甲，应为这是低等级武士的装备 
所以也不能提供什麽好防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 3 );
        set("material","heavy_metal");
        set( "weight", 200 );
        set( "value", ({ 450, "silver"}) );
}

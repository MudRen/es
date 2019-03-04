#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Cloak", "雷电披风");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "雷电披风");
        set_long(@AAA
这是一件附有雷电精灵力量的披风
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["eletric":7]));
        set( "weight", 30 );
        set( "value", ({ 700, "silver" }) );
}

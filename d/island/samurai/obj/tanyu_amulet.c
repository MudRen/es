#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu amulet", "天羽护身符");
        add( "id", ({ "amulet" }) );
        set_short("tanyu amulet", "天羽护身符");
        set_long(@AAA
这是天羽剑派特有的护身符
AAA
        );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","light_metal");
        set("special_defense",(["cold":10,"fire":10,"electric":10]));
        set( "weight", 20 );
        set( "value", ({ 860, "silver" }) );
}

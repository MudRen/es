
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult shortsword", "神秘短剑" );
        add( "id",({ "sword", "shortsword" }) );
        set_short( "神秘短剑" );
        set_long(
            "这是巴德北特.庞博所使用的短剑。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 40 );
        set( "type", "shortblade" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 180 );
        set( "value", ({ 300, "gold" }) );
}


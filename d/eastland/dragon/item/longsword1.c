
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult longsword", "神秘长剑" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "神秘长剑" );
        set_long(
            "这是把神秘长剑。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 25 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 26 );
        set( "weight", 220 );
        set( "value", ({ 300, "gold" }) );
}


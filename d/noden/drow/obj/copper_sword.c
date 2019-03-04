#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper sword","铜刃");
        add( "id",({ "sword" }) );
        set_short( "铜刃");
        set_long(
@CLONG
这是把由粗铜所打造的长剑，握柄处还有绿色的铜锈在。
CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 17 );
        set( "max_damage", 23 );
        set( "weight", 110 );
        set( "value", ({ 300, "silver" }) );
}

#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "whisk", "扫把");
        add ("id",({ "whisk"}) );
        set_short("扫把");
        set("unit", "把");
        set_long(
            "这是一把很普通的竹扫把。\n"
        );
        set( "weapon_class", 5 );
        set( "type", "blunt" );
        set( "min_damage", 3);
        set( "max_damage", 9);
        set( "weight", 55 );
        set( "value", ({ 10, "silver" }) );
}

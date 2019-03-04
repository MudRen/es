
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Chilin teeth", "麒麟牙" );
        add( "id",({ "teeth", "shortsword" }) );
        set_short( "麒麟牙" );
        set_long("这是麒麟经过数千年时光演化出的超级武器\n");
        set( "unit", "把");
        set( "weapon_class", 44 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 33 );
        set( "weight", 180 );
        set( "value", ({ 400, "gold" }) );
}


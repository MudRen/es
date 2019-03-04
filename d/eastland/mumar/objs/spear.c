#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("snake spear", "ÉßÃ¬");
        add ("id",({ "spear" }) );
        set_short("ÉßÃ¬");
        set_long(
            "Ò»Ö§ÉßÃ¬£¬Ã¬Í·ÏñÉß°ãÍäÇú£¬áİ·ğÒªÍÌÊÉµĞÈË¡£\n"
        );
        set( "unit", "Ö§" );
        set( "weapon_class", 17 );
        set( "type", "thrusting" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "weight", 190 );
        set( "value", ({ 500, "silver" }) );
}

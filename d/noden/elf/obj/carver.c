
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("carver", "�˵�");
        add ("id",({ "carver"}) );
        set_short( "�˵�" );
        set_long(
            "����һ���в˵�\n"
        );
        set("unit","��");
        set( "weapon_class", 6 );
        set( "type", "shortblade" );
        set( "min_damage", 2 );
        set( "max_damage", 5 );
        set( "weight", 40 );
        set( "value", ({ 10, "sliver" }) );
}


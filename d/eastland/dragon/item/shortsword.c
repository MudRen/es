
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult shortsword", "���ض̽�" );
        add( "id",({ "sword", "shortsword" }) );
        set_short( "���ض̽�" );
        set_long(
            "���ǰ͵±���.�Ӳ���ʹ�õĶ̽���\n"
        );
        set( "unit", "��");
        set( "weapon_class", 40 );
        set( "type", "shortblade" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 180 );
        set( "value", ({ 300, "gold" }) );
}


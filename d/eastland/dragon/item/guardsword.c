#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult longsword", "���س���" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "���س���" );
        set_long(
            "���ǰ����س�����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 16 );
        set( "max_damage", 30 );
        set( "weight", 220 );
        set( "value", ({ 600, "gold" }) );
}



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
        set( "weapon_class", 19 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 150 );
        set( "value", ({ 150, "gold" }) );
}

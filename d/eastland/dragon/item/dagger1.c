
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult dagger", "����ذ��" );
        add( "id",({ "dagger" }) );
        set_short( "����ذ��" );
        set_long(
            "����ذ�ס�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 25 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 150 );
        set( "value", ({ 120, "gold" }) );
}


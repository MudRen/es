
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("toy spear", "���ì");
        add ("id",({ "spear" }) );
        set_short( "���ì");
        set_long(
            "����һ������ߵ�ì��\n"
        );
        set( "unit", "��");
        set( "weapon_class", 3 );
        set( "type", "thrusting" );
        set( "min_damage", 2);
        set( "max_damage", 6 );
        set( "weight", 70 );
        set( "value", ({ 44, "silver" }) );
}


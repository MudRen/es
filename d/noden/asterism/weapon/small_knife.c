
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("little knife","С��");
        add ("id",({ "knife" }) );
        set_short( "С��");
        set_long(
            "����һ��С����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 5 );
        set( "type", "dagger" );
        set( "min_damage", 3);
        set( "max_damage", 7 );
        set( "weight", 50 );
        set( "value", ({ 64, "silver" }) );
}


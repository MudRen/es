
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("small dagger","Сذ��");
        add ("id",({ "dagger" }) );
        set_short( "Сذ��");
        set_long(
            "����һ��ûʲ��ɱ�����Ķ�ذ�ס�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 5 );
        set( "type", "dagger" );
        set( "min_damage", 3);
        set( "max_damage", 7 );
        set( "weight", 50 );
        set( "value", ({ 50, "silver" }) );
}



#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "demonic dagger", "��ħذ��" );
        add( "id",({ "dagger"}) );
        set_short( "��ħذ��" );
        set_long(
            "���Ƕ�ħС͵��ר��������\n"
        );
        set( "unit", "��");
        set( "weapon_class", 17 );
        set( "type", "dagger" );
        set( "min_damage", 8 );
        set( "max_damage", 17 );
        set( "second",1);
        set( "weight", 100 );
        set( "value", ({ 1200, "silver" }) );
}


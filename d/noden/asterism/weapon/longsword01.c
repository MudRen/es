
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("halfling longsword", "�����˳���");
        add ("id",({ "sword" }) );
        set_short("�����˳���");
        set_long(
            "���ǰ�����������ʹ�õĳ�����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 22 );
        set( "type", "longblade" );
        set( "min_damage", 15);
        set( "max_damage", 23 );
        set( "weight", 180 );
        set( "value", ({ 1420, "silver" }) );
}


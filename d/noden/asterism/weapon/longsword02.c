
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Brone longsword", "��ͭ����");
        add ("id",({ "sword" }) );
        set_short("��ͭ����");
        set_long(
            "������ͭ�Ƶķ���������\n"
        );
        set( "unit", "��");
        set( "weapon_class", 23 );
        set( "type", "longblade" );
        set( "min_damage", 17);
        set( "max_damage", 25 );
        set( "weight", 190 );
        set( "value", ({ 1720, "silver" }) );
}


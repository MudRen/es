
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("stone long hammer", "ʯ�Ƴ��");
        add ("id",({ "hammer" }) );
        set_short("ʯ�Ƴ��");
        set_long(
            "����һ��ʯ�Ƴ��,���ܹ���Զ���ĵ��ˡ�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 15);
        set( "max_damage", 26);
        set( "weight", 240 );
        set( "value", ({ 770, "silver" }) );
}


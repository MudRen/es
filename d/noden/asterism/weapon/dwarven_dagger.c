
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("dwarven dagger", "����ذ��");
        add ("id",({ "dagger" }) );
        set_short("����ذ��");
        set_long(
            "����һ�Ѻܷ����İ���ר��ذ��,\n"
        );
        set( "unit", "��");
        set( "weapon_class", 24 );
        set( "type", "dagger" );
        set( "min_damage", 18);
        set( "max_damage", 26 );
        set( "weight", 120 );
        set( "value", ({ 1120, "silver" }) );
}

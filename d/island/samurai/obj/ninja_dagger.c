
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja dagger", "����ذ��" );
        add( "id",({ "dagger" }) );
        set_short( "Ninja dagger", "����ذ��" );
        set_long(@AAA
����ר�õ�ذ�ף���Ȼ��С��ȷ�м��ѵ��ƻ���
AAA
        );
        set( "unit", "��");
//        set( "bleeding",5 );
        set( "weapon_class", 30 );
        set( "type", "dagger" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 80 );
        set( "value", ({ 1320, "silver" }) );
}



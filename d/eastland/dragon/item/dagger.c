
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "evil dragon dagger", "������ذ" );
        add( "id",({ "dagger","dragon" }) );
        set_short( "������ذ" );
        set_long(@C_LONG
��������������֮Ѫ�������ذ�ף�����֮���������꺮Ȫ�������꣬
��������ޱȣ�����������˸������Ľ�����â��
C_LONG
        );
        set( "unit", "��");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 23 );
        set( "max_damage", 36 );
        set( "weight", 50 );
        set( "value", ({ 400, "gold" }) );
}



#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja blade", "�̵�" );
        add( "id",({ "blade","sword" }) );
        set_short( "Ninja blade", "�̵�" );
        set_long(
            " ����һ�ѷ����ĳ���������ʿ�ŵ���ʽ����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 22 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}




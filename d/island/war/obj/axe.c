#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel axe", "�ָ�" );
        add( "id",({ "axe" }) );
        set_short( "steel axe", "�ָ�" );
        set_long(@AAA
����һ�ѷ����Ĵ󸫣�ʹ��ʿ�ű߾������Ӱ��õ�����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 25 );
        set( "type", "axe" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 170 );
        set( "value", ({ 620, "silver" }) );
}




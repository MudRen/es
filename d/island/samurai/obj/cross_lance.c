
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "cross lance","ʮ��ǹ" );
        add( "id",({ "lance","cross" }) );
        set_short( "cross lance","ʮ��ǹ" );
        set_long(@AAA
����һ�Ѿ޴��ʮ��ǹ,�����Ǹ��൱����������,��Ȼ���ò������ִ������
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 36 );
        set( "type", "thrusting" );
        set( "min_damage", 15 );
        set( "max_damage", 38 );
        set( "weight", 250 );
        set( "value", ({ 1230, "silver" }) );
}




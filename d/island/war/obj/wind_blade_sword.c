#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "wind_blade_sword", "���н�" );
        add( "id",({ "blade","sword" }) );
        set_short( "wind_blade_sword", "���н�" );
        set_long(@AAA
����һ�ѷ����ĳ���������ʿ�ŵ���ʽ����������������������
ʹ����ѽ�������ͨ�Ľ���������ɽ϶��˺�
AAA
     );
        set( "unit", "��");
//        set("bleeding", 10 );
        set("nosecond", 1 );
        set( "weapon_class", 27 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 180 );
        set( "value", ({ 820, "silver" }) );
}





#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja sword", "���ߵ�" );
        add( "id",({ "sword" }) );
        set_short( "Ninja sword", "���ߵ�" );
        set_long(@AAA
����ר�õ���������˵�����ǵ���ȴ��ƽ���ĵ�Ҫ������࣬
����������Ϊ�˷����ƶ����ĵİ�
AAA
        );
        set( "unit", "��");
//        set( "bleeding",13);
        set( "weapon_class", 25 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 120 );
        set( "value", ({ 720, "silver" }) );
}




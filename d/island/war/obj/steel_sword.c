#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel sword", "���ֳ���" );
        add( "id",({ "sword" }) );
        set_short( "steel sword", "���ֳ���" );
        set_long(@AAA
�����԰ѷ����ĳ�������������ֲ����ɵģ�����ʿ�ű߾��ر��ӵ���ʽ����
AAA
);
        set( "unit", "��");
        set( "weapon_class", 30 );
//        set( "bleeding", 5 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 28 );
        set( "weight", 170 );
        set( "value", ({ 720, "silver" }) );
}




#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "ghost shortsword", "����̽�" );
        add( "id",({ "sword", "shortsword" }) );
        set_short( "����̽�" );
        set_long(@LONG
    һ�ѵ��ι��ŵ��ľ���̽��������в����ߡ���������һ�ֲ�֪���ں�ɫ����
�������ɣ����ߵĵ�����Ƕ��һ����ɫ��ʯ�������ϵ�͸�������Ĺ�â��
LONG);
        set( "unit", "��");
        set( "weapon_class", 42 );
        set( "type", "shortblade" );
        set( "min_damage", 25 );
        set( "max_damage", 37 );
//        set( "bleeding", 10 );
        set( "weight", 50 );
        set( "value", ({ 2175, "gold" }) );
}


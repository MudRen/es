#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "moon sword", "�����²�" );
        add( "id",({ "moon","sword" }) );
        set_short( "moon sword", "�����²�" );
        set_long(@AAA
            ����һ���������²е�����˵������Ϊ����ʦ������ѽ�ʱ
            �պÿ�����ʴ�������������䵶��һ��˫��
AAA
);
        set( "unit", "��");
        set( "weapon_class", 35 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 40 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}



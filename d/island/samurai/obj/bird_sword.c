
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "bird sword", "����ǧ��" );
        add( "id",({ "bird","sword" }) );
        set_short( "bird sword", "����ǧ��" );
        set_long(@AAA
����һ�������Ĺŵ�ǧ���ڽ����Ͽ���һ�������ͼ��
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 26 );
        set( "weight", 170 );
        set( "value", ({ 1320, "silver" }) );
}





#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "willow club", "�����");
        add ("id",({ "club"}) );
        set_short("�����");
        set("unit", "��");
        set_long(@C_LONG
��Ѱ���������ð�������������Ƴɵģ��ǳ�ѧ�������˵����ѡ��
C_LONG
        );
        set( "weapon_class", 11 );
        set( "type", "bo" );                        
        set( "min_damage", 8);
        set( "max_damage", 14);
        set( "weight", 45 );
        set( "value", ({ 180, "silver" }) );
}

#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "poplar club", "��ľ��");
        add ("id",({ "club"}) );
        set_short("��ľ��");
        set("unit", "��");
        set_long(@C_LONG
��ѹ�����������ľ���Ƴɣ�������õ���ľ�ĵ��ԣ������ս���е���
���ʱ���ͨľ�����ߡ�
C_LONG
        );
        set( "weapon_class", 19 );
        set( "type", "bo" );                        
        set( "min_damage", 10);
        set( "max_damage", 16);
        set( "weight", 55 );
        set( "value", ({ 280, "silver" }) );
}

#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "copper club", "��ͭ��");
        add ("id",({ "club"}) );
        set_short("��ͭ��");
        set("unit", "��");
        set_long( @C_LONG
����һ������ͭ���ɵĹ��ӣ���������ɮ��ϲ���õ�����֮һ��
C_LONG
        );
        set( "weapon_class", 15 );
        set( "type", "bo" );                        
        set( "min_damage", 12);
        set( "max_damage", 18);
        set( "weight", 100 );
        set( "value", ({ 380, "silver" }) );
}

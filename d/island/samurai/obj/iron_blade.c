
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "iron blade", "������" );
        add( "id",({ "sword","blade" }) );
        set_short( "iron blade", "������" );
        set_long(@AAA
����һ����ͨʿ���õ�����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 10 );
        set( "type", "longblade" );
        set( "min_damage", 5 );
        set( "max_damage", 12 );
        set( "weight", 100 );
        set( "value", ({ 320, "silver" }) );
}





#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "east_feather_blade", "����Ƭ��" );
        add( "id",({ "blade","sword" }) );
        set_short( "east��feather��blade", "����Ƭ��" );
        set_long(@AAA
����һ�ѷ����ĳ���������ʿ�ŵ���ʽ����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 22 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}




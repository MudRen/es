#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonscale sword","����֮��" );
        add( "id",({ "dragonscale","sword" }) );
        set_short( "dragonscale sword","����֮��" );
        set_long(@AAA
����һ����������Ƭ����ĳ������������ޱȵ�����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 27 );
//        set( "bleeding",17 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 28 );
        set( "weight", 150 );
        set( "value", ({ 930, "silver" }) );
}
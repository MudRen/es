
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "lakonia sword", "�����ᰲ��" );
        add( "id",({ "sword" }) );
        set_short( "lakonia sword", "�����ᰲ��" );
        set_long(@AAA
����һ���������ᰲ��������ĳ���
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
//        set( "bleeding", 15 );
        set( "min_damage", 13 );
        set( "max_damage", 26 );
        set( "weight", 150 );
        set( "value", ({ 620, "silver" }) );
}



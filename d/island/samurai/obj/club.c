
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Club", "ľ��" );
        add( "id",({ "club" }) );
        set_short( "club", "ľ��" );
        set_long(@AAA
�����г��������õ�ľ��
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 22 );
        set( "type", "blunt" );
        set( "min_damage", 7 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}




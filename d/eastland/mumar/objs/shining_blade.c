#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "shining blade", "�⵶" );
        add( "id", ({ "blade" }) );
        set_short( "�⵶" );
        set_long(
                "����һ��ɢ��������ĳ�����\n" );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weight", 120 );
        set( "weapon_class", 23 );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "value", ({ 500, "silver" }) );
}

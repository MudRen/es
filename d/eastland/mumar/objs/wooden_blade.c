#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "wooden blade", "ľ��" );
        add( "id", ({ "blade" }) );
        set_short("ľ��");
        set_long(
                "����һ֧������±�ѵ���õ�ľ����\n"
        );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weapon_class", 8 );
        set( "min_damage", 4 );
        set( "max_damage", 8 );
        set( "weight", 60 );
        set( "value", ({ 80, "silver" }) );
}

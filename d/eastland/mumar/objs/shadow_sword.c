#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "shadow sword", "Ӱ��" );
        add( "id", ({ "sword" }) );
        set_short( "Ӱ��" );
        set_long(
                "����һ�Ѱ���ɫ�ĳ�������͹��ƽ�Ľ������е���Ӱ��������\n" );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weight", 120 );
        set( "weapon_class", 23 );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "value", ({ 500, "silver" }) );
}

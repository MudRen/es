#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("lance", "��ǹ");
        add ("id",({ "lance" }) );
        set_short("��ǹ");
        set_long(
            "һ�ѳ�ǹ��ǹͷ���������⡣\n"
        );
        set( "unit", "��" );
        set( "weapon_class", 13 );
        set( "type", "thrusting" );
        set( "min_damage", 6 );
        set( "max_damage", 14 );
        set( "weight", 150 );
        set( "value", ({ 200, "silver" }) );
}

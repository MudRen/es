#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("javelin", "����");
        add ("id",({ "javelin" }) );
        set_short("����");
        set_long(
            "һ�ѳ��ꡣ\n"
        );
        set( "unit", "��" );
        set( "weapon_class", 10 );
        set( "type", "thrusting" );
        set( "min_damage", 5 );
        set( "max_damage", 13 );
        set( "weight", 150 );
        set( "value", ({ 150, "silver" }) );
}

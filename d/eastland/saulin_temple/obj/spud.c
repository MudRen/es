#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "spud", "С��ͷ");
        add ("id",({ "spud"}) );
        set_short("С��ͷ");
        set("unit", "��");
        set_long(
            "����һ���������ص�С��ͷ��\n"
        );
        set( "weapon_class", 6 );
        set( "type", "blunt" );                        
        set( "min_damage", 5);
        set( "max_damage", 10);
        set( "weight", 65 );
        set( "value", ({ 80, "silver" }) );
}

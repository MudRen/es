#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "whisk", "ɨ��");
        add ("id",({ "whisk"}) );
        set_short("ɨ��");
        set("unit", "��");
        set_long(
            "����һ�Ѻ���ͨ����ɨ�ѡ�\n"
        );
        set( "weapon_class", 5 );
        set( "type", "blunt" );
        set( "min_damage", 3);
        set( "max_damage", 9);
        set( "weight", 55 );
        set( "value", ({ 10, "silver" }) );
}

#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "scoop", "����" );
        add( "id",({ "scoop" }) );
        set_short("����");
        set_long(
            "���ǰ����õ����ӡ�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 7 );
        set( "type", "blunt" );
        set( "min_damage", 2 );
        set( "max_damage", 8 );
        set( "nosecond", 1);
        set( "weight", 35 );
        set( "value", ({ 200, "sliver" }) );
}

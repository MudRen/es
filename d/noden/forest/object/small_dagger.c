#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("small dagger", "Сذ��");
        add ("id",({ "dagger"}) );
        set_short("Сذ��");
        set_long( @CLONG
���ذ��ԭ����С��������е�, �������൱��С�ɡ�
CLONG
        );
        set("unit","��");
        set( "weapon_class", 6 );
        set( "type", "dagger" );
        set( "min_damage", 3 );
        set( "max_damage", 6 );
        set( "weight", 30 );
        set( "value", ({ 10, "silver" }) );
}

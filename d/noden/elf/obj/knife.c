
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven knife", "����С��");
        add ("id",({ "knife"}) );
        set_short( "����С��" );
        set("unit", "��");
        set_long(
            "������С�ľ�������ʯͷ���ɵ����С����\n"
        );
        set( "weapon_class", 4 );
        set( "type", "dagger" );                        
        set( "min_damage", 2 );
        set( "max_damage", 5 );
        set( "weight", 35 );
        set( "value", ({ 8, "silver" }) );
}

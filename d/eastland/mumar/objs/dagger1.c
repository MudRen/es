#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "stpuid dagger", "��ذ��" );
        add( "id", ({ "dagger" }) );
        set_short( "��ذ��" );
        set_long(
                "һ�Ѷ̶��۵�ذ�ף������϶���ȱ�ڡ�\n"
        );
        set( "unit", "��" );
        set( "type", "dagger" );
        set( "weapon_class", 10 );
        set( "min_damage", 4 );
        set( "max_damage", 13 );
        set( "weight", 30 );
        set( "value", ({ 120, "silver" }) );
}

#include <mudlib.h>
 
inherit WEAPON;
 
void create()
{
        set_name("pan", "ƽ�׹�");
        set_short("ƽ�׹�");
        set_long(
                "����һ֧��ʦ�õ�ƽ�׹���\n"
        );
        set( "unit", "֧" );
        set( "weight", 80 );
        set( "type", "blunt" );
        set( "weapon_class",10 );
        set( "min_damage", 6 );
        set( "max_damage", 12 );
        set( "value", ({ 50, "silver" }) );
}

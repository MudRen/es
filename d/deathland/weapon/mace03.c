#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("little mace","С�ɵĶ�ͷ�");
        add("id",({"mace",}) );
       set_short("С�ɵĶ�ͷ�");
       set_long(
         "һ��С�ɵĶ�ͷ�.\n"
               );
	
	set( "unit", "��" );
 	set( "weapon_class", 20 );
       set("type","blunt");
	set( "min_damage", 14 );
	set( "max_damage", 26 );
	set( "weight", 110 );
	set( "value", ({ 160, "gold" }) );
}

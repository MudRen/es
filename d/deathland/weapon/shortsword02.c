#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Dwarven shortsword","���˶̽�");
        add("id",({"shortsword","sword"}) );
       set_short("���˶̽�");
       set_long(
         "���ǰ������õķ����̽�.\n"
               );
	
	set( "unit", "��" );
 	set( "weapon_class", 14 );
       set("type","shortblade");
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 100 );
	set( "value", ({ 570, "silver" }) );
}

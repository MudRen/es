#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("horn shortsword","�ŽǶ̽�");
        add("id",({"shortsword","sword"}) );
       set_short("�ŽǶ̽�");
       set_long(
         "һ����״����ŽǵĶ̽�\n"
               );
	
	set("no_sale",1);
	set( "unit", "��" );
 	set( "weapon_class", 30 );
 	//set("second",1);
    set("type","shortblade");
	set( "min_damage", 22 );
	set( "max_damage", 32 );
	set( "weight", 87 );
	set( "value", ({ 2100, "silver" }) );
}

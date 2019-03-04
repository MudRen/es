#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("horn shortsword","ºÅ½Ç¶Ì½£");
        add("id",({"shortsword","sword"}) );
       set_short("ºÅ½Ç¶Ì½£");
       set_long(
         "Ò»°ÑÐÎ×´ºÜÏñºÅ½ÇµÄ¶Ì½£\n"
               );
	
	set("no_sale",1);
	set( "unit", "°Ñ" );
 	set( "weapon_class", 30 );
 	//set("second",1);
    set("type","shortblade");
	set( "min_damage", 22 );
	set( "max_damage", 32 );
	set( "weight", 87 );
	set( "value", ({ 2100, "silver" }) );
}

#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("ice sting","冰刺");
        add("id",({"sting"}) );
       set_short("冰刺");
       set_long(
         "这是用冰晶制成的锋利短刃兵器，透明的锋刃显得不比寻常。\n");

        set( "unit", "把" );
        set( "weapon_class", 14 );
	set("type","shortblade");
        set( "min_damage", 8 );
        set( "max_damage", 16 );
	set( "weight", 80 );
        set( "value", ({ 540, "silver" }) );
}

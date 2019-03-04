#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Controlled Death Scythe", "听话的死神镰刀");
	add ("id",({ "scythe", }) );
    set_short("听话的死神镰刀");
	set_long(
	    "一把很十分锋利的大镰刀，据说是死神心爱的武器。\n"+
	    "它可以用来割草(cropp)吗? \n"
	);
	set( "unit", "把" );
	set( "weapon_class", 42 );
// set( "type", "shortblade" );
   set( "type", "longblade" );
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
    add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
     write( 
       "死神镰刀苦苦哀求地说: 请不要虐待我。\n"
    );
    return 1;
}

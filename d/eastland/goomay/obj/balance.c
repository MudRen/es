#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "balance beam", "大杆秤" );
	add( "id", ({ "beam" }) );
	set_short( "a balance beam", "大杆秤" );
	set_long(
		"You see a balance beam for trading.\n",
		"这是一把大号的杆秤，专门用来秤特大号的货物用的。\n"
	);
	set( "unit", "把" );
	set( "weight", 200 );
	setup_weapon( "polearm", 25, 15, 30 );
	set( "value", ({ 420, "silver" }) );
}

// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/elf";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Elf.
	elf::setup_race_body();
}

string query_short()
{
        if( this_object()->query("player_invisible") )
            return "(����)" + ::query_short();
        else return ::query_short();
}

//#pragma save_binary
 
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (5/1/92)
// This is a common module to the different standard objects available.
// Also thanks to Mobydick for his work here.
 
// #define DEBUG
 
#include <uid.h>
#include <move.h>
 
 
// prototypes
mixed query(string what);
varargs int set(string what, mixed value, int access_level);
int remove();
int move(mixed dest);
void add(string what, mixed arg);
varargs void delete(string what, mixed arg);
varargs void set_name(string str, string c_str);
varargs void set_short(string shortname, string c_short);
varargs void set_long(string longname, string c_long);
 
// The id parsing stuff.
int id(string str)
{
	int i;
	string *parts, *ids;
 
	ids = query("id");
	if(!pointerp(ids) || !ids) return 0;
	if(member_array(str, ids) != -1) return 1; // match!
}

int receive_object(object ob)
{
	return 1;
}
int release_object(object ob)
{
	return 1;
}
 
// The argument 'dest' is either a string or an object.
// The return values are given in move.h
// updated to use standard properties 8/14/92 buddha@tmi
// also thanks to truilkan for his "last_location" idea, which I converted.
// some stuff commented out by buddha 9/7/92 for speed
// changed to weight-only by Annihilator 10/15/93
 
int move(mixed dest)
{
	object ob;
	string err;
	int weight;
 
        if (!dest) return MOVE_NO_DEST;
	if (stringp(dest)) {
		ob = find_object(dest);
		if (!ob) { 
			err = catch(call_other(dest, "???"));
			if (err) { 
				write("Move: " + err + "\n"); 
				return MOVE_NO_DEST;
			}
			ob = find_object(dest);
		}
	}
	else ob = dest;

	if ( ob->receive_object(this_object()) ) {
		if ( environment() )
			environment()->release_object(this_object()) ;
		move_object( ob );
		return MOVE_OK;
	} 
	else 
		return MOVE_TOO_HEAVY ;
}

/*
 * To destruct objects, call 'remove()' in the object. The default here
 * is to allow destruction and update encumbrance.
 * All objects inside this object is also moved to the "outside" (if any).
 */
int remove()
{
	object super;
	int i, res ;
	object *ob_list;
 
	super = environment(this_object());
	if (super) {
		super->add("load", - query("weight")) ;
		ob_list = all_inventory(this_object());
		for (i=0; i < sizeof(ob_list); i++) {
			res = ob_list[i]->move(super);
			if (res!=MOVE_OK) {
				tell_object(super,ob_list[i]->query("name") + " vanishes! Tell a wizard!\n");
				destruct(ob_list[i]); 
			}
		}
	}
	destruct(this_object());
	return 1;
}
 
// clean_up() is called on all objects by the driver in an attempt to do some
// garbage collection.  If it returns 0, then it will never be called again,
// otherwise it will be called after an interval set in the runtime config 
// file.
// clean_up.c

int clean_up()
{
	object *inv;
	int i;

	if(userp(this_object())) return 1;

	if(environment()) return environment()->clean_up();

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
		if(userp(inv[i])) return 1;

	remove();
	return 0;
}
 
// The following functions are some frequently used setup macros.
// Most of them can be parted into several calls to set().
void set_name(string str, string c_str)
{
	if( living(this_object()) ) set_living_name( str );
	set ("name", str);
	set( "c_name", ( c_str ? c_str : str ) );
	if( !query("id") ) set("id", ({ lower_case(str) }) );
}
 
// Elon@ES (11-16-94) temp fix for chinese.
varargs void set_short(string shortname, string c_short)
{
    if (c_short) set("short", c_short );
    else set("short", shortname );
}
 
varargs void set_long(string longname, string c_long)
{
    if (c_long)	set("long", c_long );
    else set("long", longname );
}

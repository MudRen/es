//#pragma save_binary
 
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (5/1/92)
// This is a common module to the different standard objects available.
// Also thanks to Mobydick for his work here.

#include "/std/object/prop.c"
 
int receive_object(object ob)
{
	return 1;
}
int release_object(object ob)
{
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

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
		if(userp(inv[i])) return 1;

	destruct(this_object());
	return 0;
}
 
// The following functions are some frequently used setup macros.
// Most of them can be parted into several calls to set().
 
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

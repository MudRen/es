// bag.c
// A simple bag.
// Originally written by Truilkan 92/04/20.
// Updated to mudlib 0.9 by Mobydick, 10-14-92.
// This bag cannot be closed or locked. For an example of a container which
// can be both closed and locked, see /obj/chest.c.

#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_c_open_long("���С������������װһЩС������\n");
#include <compress_obj.h>
	set_name("bag", "����");
	set_short("����");
	set( "weight_apply", 70 );
	set( "weight", 10);
	set( "weight_apply", 70 );
	set( "max_load", 150);
	set( "value", ({ 5, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}

// A list for explored points.
// by Elsa ... update at Jun 15 1995

#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid(getuid());
	set_name( "list", "���а�" );
	set_short( "̽�ն����а�" );
	set_long((string)find_object_or_load("/d/noden/farwind/items/top_explore")->get_list());
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
	set( "useless", 1 );
}

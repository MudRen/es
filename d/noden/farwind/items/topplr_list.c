#include <mudlib.h>

inherit OBJECT;

void create()
{
         seteuid(getuid());
	set_name( "list", "���а�" );
	set_short( "������а�" );
	set_long( (string)"/adm/daemons/topplayer"->get_list(),
			  (string)"/adm/daemons/topplayer"->get_list(1) );
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 5, "silver" }) );
	set( "useless", 1 );
//	set( "prevent_get", 1 );
}

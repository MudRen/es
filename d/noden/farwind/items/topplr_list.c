#include <mudlib.h>

inherit OBJECT;

void create()
{
         seteuid(getuid());
	set_name( "list", "ÅÅĞĞ°ñ" );
	set_short( "Íæ¼ÒÅÅĞĞ°ñ" );
	set_long( (string)"/adm/daemons/topplayer"->get_list(),
			  (string)"/adm/daemons/topplayer"->get_list(1) );
	set( "unit", "¾í" );
	set( "weight", 5 );
	set( "value", ({ 5, "silver" }) );
	set( "useless", 1 );
//	set( "prevent_get", 1 );
}

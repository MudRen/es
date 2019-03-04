#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "copper key", "Í­Ô¿³×" );
	add( "id", ({ "key" }) );
   set_short( "Í­Ô¿³×" );
   set_long(
            "Ò»°ÑÉúÐâµÄÍ­Ô¿³×¡£\n" );
   set( "unit", "°Ñ" );
   set( "to_lock", "DBEGGAR_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

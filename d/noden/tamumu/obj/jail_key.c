#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "jail key", "¼àÓüÔ¿³×" );
	add( "id", ({ "key" }) );
	set_short( "¼àÓüÔ¿³×" );
	set_long(
		"ÕâÊÇËşÄ·Ä·¼àÓüµÄÔ¿³×£¬ÉÏÃæÕ´ÂúÁËÑª¼£¡£\n"
	);
	set( "to_lock", "TAMUMU_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 15, "silver" }) );
	set( "no_sale", 1 );
}

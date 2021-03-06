#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "wooden club", "木棒" );
	add( "id", ({ "club" }) );
   set_short( "木棒" );
	set_long(
		"一根看起来没有什麽特别的木棒，握柄部份用布条缠了几圈。\n"
	);
	set( "unit", "根" );
	set( "type", "blunt" );
	set( "weapon_class", 3 );
	set( "min_damage", 2 );
	set( "max_damage", 6 );
	set( "weight", 60 );
	set( "value", ({ 10, "silver" }) );
}

#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "grand axe", "巨斧" );
	add( "id", ({ "tamumu grand axe", "axe" }) );
	set_short( "塔姆姆巨斧" );
	set_long("这把巨斧的斧刃很宽，而且相当锋利，能对敌人造成颇大的杀伤力。\n"
	);
	set( "unit", "把" );
	set( "type", "axe" );
	set( "weapon_class", 25 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "nosecond", 1 );
	set( "weight", 200 );
	set( "value", ({ 480, "silver" }) );
}

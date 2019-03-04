#include <mudlib.h>

inherit WEAPON;

string C_NAME="[37;1m����[37;0m";

void create()
{
	set_name( "Sword of Antilordeus", C_NAME );
	add( "id", ({ "sword", "antilordeus" }) );
	set_short( C_NAME );
	set_long(@LONG
LONG
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 46 );
	set( "min_damage", 34 );
	set( "max_damage", 52 );
	set( "weight", 140 );
	set( "hit_func", "weapon_hit" );
	set( "value", ({ 600, "silver" }) );
	set( "no_sale", 1 );
}

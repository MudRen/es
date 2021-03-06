#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Moraz blade", "默雷兹长刀" );
	add( "id", ({ "blade", "sword" }) );
	set_short( "Moraz Blade", "默雷兹长刀" );
	set_long(
		"You see a long sword with a long crane. The sword is well balanced\n"
		"for those mastering usage of swords and lance.\n",
		"这是一把造型很像长枪的长刀，它的刀柄很长，并且改良过刀身的平衡，使得\n"
		"擅於使用长剑和枪型武器的人能十分快速地挥动这把刀。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 110 );
	set( "nosecond", 1 );
	set( "bleeding", 10 );
	set( "weapon_class", 33 );
	set( "min_damage", 13 );
	set( "max_damage", 30 );
	set( "value", ({ 1340, "silver" }) );
	set( "no_sale", 1 );
}

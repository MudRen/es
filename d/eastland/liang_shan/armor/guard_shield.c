#include <../takeda.h>

inherit ARMOR;

void create()
{
	set_name( "Icy shield", "寒水冰盾" );
	add( "id", ({ "shield" }) );
	set_short( "Icy shield", "寒水冰盾" );
	set_long(
		"??\n",
		"这面盾是由湖心深处之千年坚冰所制成，尚未触碰就感到寒冷．\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "elemental" );
	set( "armor_class", 6 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "fire":12 ]) );
	set( "weight", 240 );
	set( "value", ({ 2400, "silver" }) );
}

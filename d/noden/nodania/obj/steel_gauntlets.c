#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel gauntlets", "������" );
	add( "id", ({ "gauntlets" }) );
	set_short( "������" );
	set_long(
		"����һ˫���Ƶ����ס�\n"
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "weight", 50 );
	set( "value", ({ 880, "silver" }) );
}

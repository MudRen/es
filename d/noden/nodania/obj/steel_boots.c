#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel boots", "��սѥ" );
	add( "id", ({ "boots" }) );
	set_short( "��սѥ" );
	set_long(
		"����һ˫���Ƶ�սѥ��\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}

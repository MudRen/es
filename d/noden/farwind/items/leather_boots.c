#include "../farwind.h"

inherit ARMOR;

void create()
{
	set_name("leather boots", "Ƥѥ");
	add( "id", ({ "boots" }) );
	set_short("Ƥѥ");
	set_long(
		"��˫Ƥ�Ƶĳ�ѥ�ܱ��������ߵĽŲ���\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 6 );
	set( "defense_bonus", 0 );
    set( "special_defense",
               ([ "cold":3, "fire":-3, "acid":2 ]) );
	set( "weight", 30 );
	set( "value", ({ 48, "gold" }) );
}

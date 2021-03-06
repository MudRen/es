#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder gloves", "雷电手套" );
	add( "id", ({ "glove", "gloves", }) );
	set_short( "雷电手套" );
	set_long( 
@C_TOPIC
雷之护卫所戴的手套，隐约可以听到有隆隆的雷声传出。
C_TOPIC
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "defense_bonus", 2 );
	set( "special_defense",
	    ([ "electric":10, "poison":-5 ]) );
	set( "extra_skills", ([ "parry":10 ]) );    
	set( "extra_stats", ([ "int": -1,"str": -1 ]) );
	set( "weight", 50 );
	set( "value", ({ 1700, "silver" }) );
}

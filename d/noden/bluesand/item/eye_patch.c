#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black eye patch", "黑眼罩" );
	add( "id", ({ "eye patch", "patch" }) );
   set_short( "黑眼罩" );
	set_long(
		"一副看起来很滑稽的黑色眼罩，这副眼罩的主人一定是认为带著这样的眼罩\n"
		"看起来很酷。\n"
	);
	set( "unit", "副" );
	set( "type", "head" );
	set( "material","leather");
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense",(["electric":1,"clod":1]) );
	set( "value", ({ 250, "silver" }) );
	set( "weight", 15 );
}

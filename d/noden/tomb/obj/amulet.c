#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "护身符" );
   set_short( "蜘蛛护身符" );
	set_long(
		"这个护身符是一个蜘蛛形状的小包包，里面装满了奇怪的药粉或香料之类\n"
		"的东西，闻起来很刺鼻。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "poison":2, "fire":-2 ]) );
	set( "value", ({ 290, "silver" }) );
}

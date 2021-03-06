#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fighter's robe", "武斗服" );
	add( "id", ({ "robe" }) );
	set_short( "an fighter's robe", "武斗服" );
	set_long(
		"You see a fighter's robe.\n",
		"这是一件武术修行者爱穿的衣服，或许它不能提供很好的保护，但是可以使人更敏捷。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 15 );
        set( "defense_bonus", 7 );
        set("special_defense",(["none":30, ]));
        set("extra_stats",(["dex": 1,"con":-1 ,]));
	set( "value", ({ 650, "silver" }) );
}

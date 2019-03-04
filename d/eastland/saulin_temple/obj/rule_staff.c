#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("staff of rule", "守戒棍");
	add ("id", ({ "staff" }) );
	set_short( "守戒棍" );
	set_long(
		"这是少林的戒律院执事僧所用的法棍，代表了少林寺的戒律。\n"
	);
	set("type", "bo");
	set("weapon_class", 25);
	set("min_damage", 18);
	set("max_damage", 28);
	set("weight", 150);
	set("value", ({ 755, "silver" }) );
}

#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "dog beater bo", "打狗棒" );
	add ("id", ({ "dog beater", "bo" }) );
	set_short( "Dog Beater Bo", "打狗棒" );
	set_long(
		"This is the legendary weapon of beggar's gang. It looks thin\n"
		"and light, but it is certainly a powerful weapon if you have\n"
		"learned skill of dog beating.\n",
		"这是丐帮的镇帮之宝打狗棒，它看起来绿油油的一根细竹棒，但却是\n"
		"威力十分强大的武器，如果你有机会学到打狗棒法的话。\n"
	);
	set_c_verbs( ({
		"%s往前一探，刺向%s", "倒提%s，斜挑%s", "%s疾点%s",
		"横举%s，却突然一腿踢向%s" 
	}) );
	set ("type", "thrusting");
	set ("weapon_class", 40);
	set ("min_damage", 13);
	set ("max_damage", 40);
	set ("weight", 30);
	set ("value", ({ 400, "gold" }) );
}

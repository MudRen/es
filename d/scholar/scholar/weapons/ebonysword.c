#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Ebony Sword", "焦殇剑" );
	add( "id", ({ "sword" }) );
	set_short( "Ebony Sword", "焦殇剑" );
	set_long(
		"You see a black longsword with a smell of burning spices.\n",
		"这是一把通体呈墨黑色的剑，你把剑刃向著亮光处一照，竟是半点\n"
		"光泽也没有，仍是墨色一片。你隐约可以嗅到剑身散发出一股烧艾\n"
		"草的焦味。\n"
	);
	set( "unit", "把" );
	set( "weight", 60 );
	setup_weapon( "longblade", 30, 24, 30 );
	set( "bleeding", 10 );
	set( "value", ({ 365, "gold" }) );
	set( "no_sale", 1 );
}

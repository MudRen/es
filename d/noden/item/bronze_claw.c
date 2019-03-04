#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze claws", "青铜爪" );
	add( "id", ({ "claw", "claws" }) );
   set_short( "青铜爪" );
	set_long(
		"这是一双沾满暗红色血迹的青铜爪，看起来相当重。\n"
	);
	set( "unit", "双" );
	set( "second", 1 );
	setup_weapon( "unarmed", 22, 13, 17 );
	set( "bleeding", 15 );
	set( "weight", 140 );
	set( "value", ({ 470, "silver" }) );
	set_c_verbs( ({ "用%s往%s一抓", "%s划出一道暗红的血光，扫过%s",
		"的%s「刷」的一声，往%s划去" }) );
}

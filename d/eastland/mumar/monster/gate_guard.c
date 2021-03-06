#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "gate guard", "城门守卫" );
	add( "id", ({ "guard" }) );
        set_short("城门守卫");
	set_long(
		"这个城门守卫是个典型的彪型大汉，站在你面前像座铁塔一般，他的任务\n"
		"是守卫牧马关的城门。\n"
	);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 80 );
	set_skill( "block", 80 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 600 );
	set_natural_armor( 80, 20 );
	set_natural_weapon( 5, 10, 10 );

	wield_weapon( "/d/eastland/mumar/obj/glaive" );
	equip_armor( "/d/eastland/mumar/obj/shield" );
}

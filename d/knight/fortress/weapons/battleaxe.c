#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("steel battleaxe", "战斧");
	add( "id", ({ "axe", "battleaxe" }) );
	set_short( "钢铸战斧" );
	set_long(
		"这把战斧看起来沈重、锋利，是件战士级的高级武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 190 );
	setup_weapon( "axe", 31, 22, 35 );
	set( "bleeding", 10 );
	set( "value", ({ 980, "silver" }) );
}

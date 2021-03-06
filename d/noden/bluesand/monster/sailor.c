#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "sailor", "水手" );
   set_short( "水手" );
	set_long(
		"你看到一名粗壮、浑身肌肉的水手，他对你视若无睹。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 7 );
	set( "wealth/silver", 20 );
	set( "max_hp", 90 );
	set( "hit_points", 90 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 10 );
}

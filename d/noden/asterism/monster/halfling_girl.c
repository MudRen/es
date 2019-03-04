#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "halfling girl", "半身人小女孩" );
	add("id",({"girl","halfling"}) );
   set_short( "半身人小女孩" );
	set_long(
		"你看到带著笑脸的半身人女孩,她正高高兴兴地载歌载舞.\n"
	);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "alignment", 400 );
	set_natural_armor( 20, 1 );
	set_natural_weapon( 5 , 1 , 2 );
	set_perm_stat( "kar", 10 );
	set( "wealth/silver", 25 );
	wield_weapon(WEAPONS"small_knife");
}


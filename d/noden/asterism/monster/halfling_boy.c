#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "halfling boy", "������С�к�" );
	add("id",({"boy","halfling"}) );
   set_short( "������С�к�" );
	set_long(
		"�㿴������Ц���İ������к�,�����߸����˵��ظ�����.\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 320 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 10 );
	set( "wealth/silver", 22 );
	wield_weapon(WEAPONS"small_pick");
}


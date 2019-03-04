#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "halfling girl", "������СŮ��" );
	add("id",({"girl","halfling"}) );
   set_short( "������СŮ��" );
	set_long(
		"�㿴������Ц���İ�����Ů��,�����߸����˵��ظ�����.\n"
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


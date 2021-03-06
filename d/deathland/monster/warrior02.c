
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "dwarf old warrior", "矮人老战士" );
	add ("id", ({ "warrior", "dwarf", }) );
	set_short( "an old dwarf warrior", "矮人老战士" );
	set_long(
	"   \n",
    "一个很老的矮人战士,在数十年的战斗之中,他是少数能活下来而退休的矮人\n");

    set("alignment",-200);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "kar", 20 );
	set ("wealth", ([ "silver": 400 ]) );
	set_natural_weapon(3,7,12);
	set_natural_armor(66,12);
    set ("weight", 300);
    set_skill("blunt",75);
    set_skill("parry",80);
	wield_weapon(Weapon"/hammer01"); 
}

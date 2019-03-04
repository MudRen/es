
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(5);
	set_name( "Dwarf older", "矮人老者" );
	add ("id", ({ "older", "dwarf", }) );
	set_short( "Dwarf older", "矮人老者" );
	set_long(
    "一个老矮人,或许\年轻时他是个战士,但是现在他只想平平安安的活著\n"
     );
    set("alignment",0);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon(4,2,6);
	set_natural_armor(26,0);
    set ("weight", 300);
	wield_weapon(Weapon"/stick01");
}

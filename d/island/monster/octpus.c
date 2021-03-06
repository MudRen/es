
#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name("octpus", "大章鱼");
	add("id",({"octpus"}));
	set_short("大章鱼");
	set_long(@LONG
一只超大型的章鱼，它的八只触手正不断的挥动著，你还是离它
远点好了。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -250 );
	set("max_hp",600);
	set("likefish",1);
	set("hit_points",600);
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar",16 );
	set_natural_weapon(45,12,24);
	set_skill( "unarmed" , 55 );
	set_natural_armor(52,15);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "头部", "触手" }) );
	set_c_verbs( ({ "%s挥动它的触手向%s鞭打而去" }) );
}

int emit_lick()
{
	object victim;

	if( random(19)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n这章鱼用它的触手把"+victim->query("c_name")+"紧紧地捆住\n\n"
		  );
	  victim->receive_damage(1+random(4));
	  report(victim);	
	  return 1;
      }
}
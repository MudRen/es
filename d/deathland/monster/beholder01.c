
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("Dead eye", "死亡之眼");
	add("id",({"eye","beholder"}));
	set_short("a dead eye", "死亡之眼");
	set_long(
	    "A terrible dead eye,\n",
	    "一只令人惧怕的死亡之眼.\n"
	);
	set( "unit", "只" );
	
	set_perm_stat("int",22);
	set_perm_stat("str", 5);
	
	set( "alignment", -550 );
	set_natural_weapon( 25, 13, 27 );
	set_natural_armor( 60, 10 );
	set( "tactic_func", "magic_attack" );
	set("special_defense",(["all":25, "none":10]) );
	set_c_limbs( ({ "头部", "眼睛" }) );
	set_c_verbs( ({ "%s用它的眼睛瞪著%s" }) );
    equip_armor(Armour"/globe01");
}

int magic_attack()
{
	object victim;

	if( !(victim=query_attacker()) || random(10)<4 ) return 0;
	tell_room( environment(this_object()), 
		"这死亡之眼,用著它的眼睛发出一道邪恶的死光,直向"+victim->query("c_name")+"射去\n"
	);
	report(this_object(),victim);
	victim->receive_special_damage("evil",14+random(8));	
	return 1;
}

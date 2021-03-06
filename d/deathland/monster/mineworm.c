
#include "../echobomber.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("mine huge worm", "矿坑巨虫");
	add("id",({"worm"}));
	set_short("A mine huge worm", "矿坑巨虫");
	set_long(
		"You see a very very huge worm,which is searching food\n"
		"poisonus.\n",
	    "这是一条十分巨大的怪虫,似乎可以一口把你给吞下.\n"
	);
	set( "unit", "条" );
	set( "alignment", -400 );
	set("aggressive",1);
	set_natural_weapon(7,3,4);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "头部", "身体" }) );
	set_c_verbs( ({ "%s张开它的大口，用它的牙齿向%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"巨虫的嘴巴喷出一股紫色的浓稠液体，刚好喷在你的面前 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 12, 4 );
	return 1;
}

#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("snake", "青竹丝");
	set_short("青竹丝");
	set_long(
		"一条翠绿的青竹丝。\n"
	);
	set( "unit", "条" );
	set( "alignment", -300 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "emit_poison" );
	set( "chat_chance",15);
	set( "chat_output", ({
		"青竹丝在你的脚边游走。\n" }) );
	set_c_limbs( ({ "头部", "身体", "尾巴" }) );
	set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(15)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"青竹丝张开嘴巴向你咬下，你觉得一阵刺痛 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 20, 3 );
	return 1;
}

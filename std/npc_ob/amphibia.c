// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> npc.c -> monster.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>
#include <conditions.h>

inherit NPC;

void create()
{
	::create();

	// Setup extra properties for Race Amphibia.
	setup_race_body();
}

void setup_race_body()
{
	set("race", "amphibia");

	// Amphibia has no any special defense.
	set("special_defense", ([ "fire": -20, "cold": -10, "acid": 50,
		"poison": 30, "mental": 0, "electric": 0, "energy": 0,
		"magic": 0, "evil": 0, "divine": 0, ]) );

	// Apply the heal_up conditions.
	if( query("max_hp") ) HEAL_HP->apply_effect(body, 12,  1);
	if( query("max_sp") ) HEAL_SP->apply_effect(body, 10,  1);

	// These variables are used for /adm/daemons/combat_d.c
	set_verbs( ({ "punch", "kick", "poke", "grab", }) );
	set_c_verbs( ({ "%s�������%s", "%s����%sһ��",
		"%s�ſ���%s����", }) );
	set_limbs( ({ "face","legs", "neck", "feet", "backside",
		"stomach", }) );
	set_c_limbs( ({ "ͷ��", "ǰ��", "���", "����", "����", }) );
}

//#pragma save_binary

// This is a default race body for Monster, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.
// This race must be ALWAYS used ONLY for NPC.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "monster");

	// Monster has no any special defense.
	body->set("special_defense", ([ "fire": 0, "cold": 0, "acid": 0,
		"poison": 0, "mental": 0, "electric": 0, "energy": 0,
		"magic": 0, "evil": 0, "divine": 0, ]) );

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10,  1);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
}

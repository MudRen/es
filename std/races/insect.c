//#pragma save_binary

// This is a race body for Insect, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.
// This race is only used for NPC now.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "insect");

	// Insect has no any special defense.
	body->set("special_defense", ([ "fire": -10, "cold": -10, "acid": 10,
		"poison": 10, "mental": 10, "electric": 10, "energy": 10,
		"magic": 10, "evil": 10, "divine": 10, ]) );

	// This variable effects the critical medication resistance.
//	if( userp(body) ) body->set("constitution", 20);

	// the natural age of Insect.
//	if( userp(body) ) body->set("natural_gae", 1);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  9,  2);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  9,  1);
//	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
//	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 7);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s��׼%sһ��ҧ��", "%s����%sһ��",
		"%s�ݺݵ���%sҧ��", }) );
	body->set_c_limbs( ({ "����", "ǰ��", "���", "ͷ��",
		"����", "���", "С��", }) );
}

// These functions are used for race Insect.
// Please don't cover the functions in user.c.
// These are not used now because only NPC have this race.
/*
int query_natural_life() { return 5; }

// define the cost of advance stats for Insect.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 100, "dex": 100,
		"con": 100, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 100, "dex": 100,
		"con": 100, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat) > 3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return stat_exp_rate[stat];
}

// The block_wield() and block_wear() is to check wheather if the player
// can wield a weapon or wear an armor. If the player is not allowed to
// equip the weapon or armor, return 1 to stop.
int block_wield(object obj)
{
	return 0;
}

int block_wear(object obj)
{
	string *allow_types = ({ "body", "head", "arms", "hands", "legs",
		"feet", "shield", "cloak", "misc","finger" });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}
*/

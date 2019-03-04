//#pragma save_binary

// This is a race body for Beholder, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "beholder");

	// Beholder has terrible special defense.
	body->set("special_defense", ([ "fire": 20, "cold": 20, "acid": 20,
		"poison": 20, "mental": 50, "electric": -35, "energy": -15,
		"magic": 50, "evil": 20, "divine": -35, ]) );

	// This variable effects the critical medication resistance.
	if( userp(body) ) body->set("constitution", 20);

	// the natural age of Beholder.
	if( userp(body) ) body->set("natural_age", 120);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  3,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 3);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s���۷����ƹ�, ����%s", "%sС�۷����̹�, ����%s",
		"%s��Բ����������ײ%s", "%s��ռ����һ��Ĵ���, ҧס%s", }) );
	body->set_c_limbs( ({ "����", "����", "С��", "����", }) );
}

// These functions are used for race Beholder.
// Please don't cover the functions in user.c.

int query_natural_life() { return 700; }

// Define the cost of advance stats for Beholder.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 160, "int":  40, "dex": 140,
		"con": 100, "pie":  60, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 160, "int": 40, "dex": 140,
		"con": 100, "pie": 60, "kar": 100,
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
	string *allow_types = ({ "globe", "misc", });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}

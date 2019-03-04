//#pragma save_binary

// This is a race body for Halfling, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "halfling");

	// Halfling has no any special defense.
	body->set("special_defense", ([ 
		"poison": -3, 
		"magic": -2, "evil": 5,]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 27);

	// the natural age of Halfling.
	if( userp(body) ) body->set("natural_age", 20);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 12,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 20);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 6);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
*/
}

// These functions are used for race Halfling.
// Please don't cover the functions in user.c.

int query_natural_life() { return 180; }

// define the cost of advance stats for Halfling.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 120, "int": 120, "dex":  60,
		"con": 120, "pie": 120, "kar":  60,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 120, "int": 120, "dex":  60,
		"con": 120, "pie": 120, "kar":  60,
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

// This function checks if this race can mount other animals.
int valid_mount(object ob)
{
	return (int)ob->query("mounted");
}

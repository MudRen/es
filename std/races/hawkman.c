//#pragma save_binary

// This is a race body for Hawkman, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "hawkman");

	// Hawkman has no any special defense.
	body->set("special_defense", ([ "cold": 10, 
		"poison": 3, "mental": -10, "electric": 10,
		"magic": -10, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 32);

	// the natural age of Hawkman.
	if( userp(body) ) body->set("natural_age", 18);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  8,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 12,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 6);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
*/
	// Hawkman has natural Weapon Class.
	body->set("natural_weapon_class1", "@@query_hawkman_wc_bonus" );
	body->set("natural_weapon_class2", "@@query_hawkman_wc_bonus" );
}

// These functions are used for race Hawkman.
// Please don't cover the functions in user.c.

int query_natural_life() { return 150; }

// define the cost of advance stats for Hawkman.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 130, "dex":  70,
		"con":  80, "pie": 140, "kar":  80,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 130, "dex":  70,
		"con":  80, "pie": 140, "kar":  80,
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

int query_hawkman_wc_bonus()
{
	return (int)this_object()->query_level() / 2;
}

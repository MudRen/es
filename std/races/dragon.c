//#pragma save_binary

// This is a race body for Dragon, Created by Annihilator,
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
	body->set("race", "dragon");

	// Dragon has terrible special defense.
	body->set("special_defense", ([ "fire": 100, "cold": 80, "acid": 50,
		"poison": 30, "mental": 20, "electric": 60, "energy": 40,
		"magic": 20, "evil": 0, "divine": 0, ]) );

	// This variable effects the critical medication resistance.
//	if( userp(body) ) body->set("constitution", 30);

	// the natural age of Dragon.
//	if( userp(body) ) body->set("natural_gae", 60);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10,  3);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10 , 3);
//	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
//	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 7);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s���Ӵ�ĳ��, ����%s", "%s��צץ��%s",
		"%s�ſ���%sҧ��", "%s��β��ɨ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "����", "С��", "���", "β��", }) );

	// The default tactic function.
	if( !userp(body) ) body->set("tactic_func", "fire_breath");
}

// The default tactic function for a dragon.
int fire_breath()
{
	object me, victim;

	if( random(20) > 3 ) return 0;
	me = this_object();
	if( !victim = (object)me->query_attacker() ) return 0;
	if( !present(victim, environment(me)) ) return 0;
	tell_object(victim, can_read_chinese(victim)?
		sprintf(set_color("\n%sͻȻ�ſ���������������Ȼ��!!\n\n", "HIR", victim),
			me->query("c_name")):
		sprintf(set_color("\n%s breathe at you!!\n\n", "HIR", victim),
			me->query("cap_name")) );
	tell_room(environment(me), ({
		sprintf("\n%s breathe at %s!!\n\n", me->query("cap_name"),
			victim->query("name")), 
		sprintf("\n%sͻȻ�ſ���%s����������Ȼ��!!\n\n",
			me->query("c_name"), victim->query("c_name")) }),
		({ me, victim }) );
	victim->receive_special_damage("fire", (int)me->query_level()*4);
	return 1;
}

// These functions are used for race Dragon.
// Please don't cover the functions in user.c.
// These are not used because this race is used for NPC now.
/*
int query_natural_life() { return 1000; }

// define the cost of advance stats for Dragon.
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

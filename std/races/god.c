//#pragma save_binary

// This is a race body for God, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "god");

	// God has super special defense.
	body->set("special_defense", ([ "all":100, "none":100, ]) );

	// This variable effects the critical medication resistance.
	if( userp(body) ) body->set("constitution", 100);

	// God is always 18 years old. :)
	if( userp(body) ) body->set("natural_age",
		(18-(int)body->query_age()/86400));

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10, 10);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10, 10);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 30);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 30);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s����΢Ц, ����%s", "%s�������%sһ��",
		"%s������ͻȻ����һ������, ����%s", "%s���Ϸų����ɹ�â, ��ҫ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"���", "�Ҽ�", "����", "С��", }) );

	// God has super Power.
	body->set("natural_weapon_class1", 75);
	body->set("natural_min_damage1", 30);
	body->set("natural_max_damage1", 60);
	body->set("natural_weapon_class2", 75);
	body->set("natural_min_damage2", 30);
	body->set("natural_max_damage2", 60);
	body->set("natural_armor_class", 200);
	body->set("natural_defense_bonus", 100);

	// God has all properties of all races.
	body->set("dark_sight", 1);
}

// These functions are used for race God.
// Please don't cover the functions in user.c.

int query_natural_life()
{
	return (50018+(int)this_object()->query_age()/86400);
}

// define the cost of advance stats for God.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 10, "int": 10, "dex": 10,
		"con": 10, "pie": 10, "kar": 10,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 10, "int": 10, "dex": 10,
		"con": 10, "pie": 10, "kar": 10,
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
	return 0;
}

// This function checks if this race can mount other animals.
int valid_mount(object ob)
{
	return (int)ob->query("mounted");
}

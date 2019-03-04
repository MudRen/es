//#pragma save_binary

// This is a race body for Centaur, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "centaur");

	// Centaur has little special defense.
	body->set("special_defense", ([ "fire": 3, "cold": -10, "acid": -10,
		"poison": 20, "mental": -25, "electric": 2, "energy": 3,
		"magic": -2, "evil": -3, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 27);

	// the natural age of Centaur.
	if( userp(body) ) body->set("natural_age", 20);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  8,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 7);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%sͻȻԾ��, ˫����%s����", "%s��������%sһ��",
		"%s��ȭ��%s�͡�", "%s˫����%s����", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "����" }) );

	// Extra command for Centaur.
	add_action("do_hoof", "hoof");
}

// These functions are used for race Centaur.
// Please don't cover the functions in user.c.

int query_natural_life() { return 90; }

// define the cost of advance stats for Centaur.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str":  80, "int": 120, "dex": 100,
		"con":  90, "pie": 120, "kar":  90,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str":  80, "int": 120, "dex": 100,
		"con":  90, "pie": 120, "kar":  90,
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
	string *allow_types = ({ "body", "head", "arms", "hands", "shield",
		"cloak", "misc", "finger", "saddle", });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}

int do_hoof(string arg)
{
	object me, dest;
	int chance;

	me = this_player();
	if( !arg || arg == "" || me->query("stop_attack") ) return 0;
	dest = present( arg, environment(me) );
	if( !dest || !living(dest) ) 
		return notify_fail("��Ҫ��˭��\n");

	if( dest->query("no_attack") )
		return notify_fail("�㲻������һ\n");

        if ( userp(dest) && ((int)dest->query_level()<5) )
                return notify_fail("�㲻���۸��͵ȼ���� !!\n");
	
	if ( userp(dest) && ((int) me->query_level()<5) )
		return notify_fail("��ȼ�̫��,��׼PK��\n");

	if ( dest->query_temp("be_hoofed") )
		return notify_fail("����һﾯ���Ժܸߣ���û�л���������\n");

	chance = 50 + (int)me->query_level() * 7 - (int)dest->query_level() * 7;
	if( chance > 95 ) chance = 95;
	if( chance < 5 ) chance = 5;

	dest->kill_ob(me);
	me->kill_ob(dest);
	dest->set_temp("be_hoofed",1);
	if( random(100) < chance ) {
		tell_object( me, 
			sprintf("\n��̧�����ȣ���%s�߷��˸�������\n\n", dest->query("c_name")));

		tell_room( environment(me), 
			sprintf("\n%sͻȻ̧�����ȣ���%s�߷��˸�������\n\n",
				me->query("c_name"), dest->query("c_name")) ,
			({ me, dest }) );
		tell_object( dest,
			sprintf("\n%sͻȻ̧�����ȣ������ߵ���ǰֱð���ǣ�\n\n",
				me->query("c_name"))
			    );

                dest->block_attack( 1 + random(4) );
		dest->receive_damage( (int)me->query_level() );
		dest->set_temp("msg_stop_attack", 
			"( �㱻�߷��˸�������ʹ������������ )\n" );
	} else {
		tell_object( me, 
			sprintf("\n��̧��������%s��ȥ����������ˣ�\n\n",
				dest->query("c_name"))
			    );

		tell_room( environment(me), 
			sprintf("\n%sͻȻ̧��������%s��ȥ������û�����У�\n\n",
				me->query("c_name"), dest->query("c_name")) ,
			({ me, dest }) );
		tell_object( dest, 
			sprintf("\n%sͻȻ̧�������������˹��������Ǳ�������\n\n",
				me->query("c_name"))
			    );
	}
	return 1;
}

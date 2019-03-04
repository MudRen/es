//#pragma save_binary

// This is a race body for Orc, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "orc");

	// Orc has less special defense.
	body->set("special_defense", (["cold": 5, 
		"poison": 10, "mental": -25, 
		"magic": 5,]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 35);

	// the natural age of Orc.
	if( userp(body) ) body->set("natural_age", 8);

	// Apply the heal_up conditions.
	HEAL_HP->apply_effect(body,  6,  1);
	HEAL_SP->apply_effect(body, 15,  1);
	HEAL_TP->apply_effect(body, 30, 10);
	HEAL_BODY->apply_effect(body, 30, 9);
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  6,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 15,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 9);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
*/
	// Orc has natural damage.
	body->set("natural_max_damage1", "@@query_orc_damage_bonus");
	body->set("natural_max_damage2", "@@query_orc_damage_bonus");
        add_action("do_feast","feast");
}

// These functions are used for race Orc.
// Please don't cover the functions in user.c.

int do_feast()
{
        object *inv ;
        int i,j;
        inv = all_inventory(environment());
        j = 0;
        for ( i = 0 ; i < sizeof(inv) ; i++) {
                if ( !living(inv[i]) && (string)inv[i]->query("name")=="corpse"&&
		!inv[i]->query("user_corpse")) {
                        write(sprintf("���%sץ������ϣ������Ը�Ǭ�� !!\n",
                                      inv[i]->query("short")));
                        tell_room(environment(),sprintf("%s����һ������%sץ�������������¿��˸�Ǭ�� ... �� ...\n",
							this_object()->query("c_name"),inv[i]->query("short")),this_object());

			this_object()->add("hit_points",1+(int)this_object()->query_level()*(int)inv[i]->query("weight")/2000);
			if ( (int)this_object()->query("hit_points") > (int)this_object()->query("max_hp"))
                                this_object()->set("hit_points",(int)this_object()->query("max_hp"));
                        inv[i]->remove();
                        j ++ ;
		}
	}
        if ( !j ) {
                write("�����ʲ�᣿�ҿ����Ƕ����� !! \n");
                return 1;
	}
        write("������죬���Ķ��ӣ�����ش��˸����á�\n");
        tell_room(environment(),sprintf("%s�����죬���Ķ��ӣ�����ش��˸����á�\n",this_object()->query("c_name")),this_object());
        return 1;
}

int query_natural_life() { return 45; }

// define the cost of advance stats for Orc.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str":  70, "int": 130, "dex": 100,
		"con":  60, "pie": 120, "kar": 120,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str":  70, "int": 130, "dex": 100,
		"con":  60, "pie": 120, "kar": 120,
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

int query_orc_damage_bonus()
{
	object body, weap1, weap2;

	body = this_object();
	weap1 = body->query("weapon1");
	weap2 = body->query("weapon2");

	// if unarmed or two-handed weapon.
	if( weap1==weap2 )
		return (int)body->query_level() / 3;
	else
		return 0;
}

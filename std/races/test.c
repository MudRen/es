//#pragma save_binary

// This is a race body for Test, Created by Ruby,
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "TEST");

	// Elf has little special defense.
	body->set("special_defense", ([ "fire": -25, "cold": -10, "acid": -10,
		"poison": -25, "mental": 70, "electric": -10, "energy": -10,
		"magic": 20, "evil": -30, "divine": 10, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 25);

	// the natural age of Elf.
	if( userp(body) ) body->set("natural_gae", 100);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 12,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  8,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 4);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
		
	// Elf has weapon class bonus.
	body->set("natural_weapon_class1", "@@query_elf_WC_bonus");
        // the special commands for user elf.
        add_action("do_invisible", "invisible");
        add_action("do_visible", "visible");
}

// These functions are used for race Elf.
// Please don't cover the functions in user.c.

int do_invisible(string arg)
{
        if( this_object()->query("player_invisible") )
                return notify_fail("���Ѿ������ˡ�\n");
        this_player()->set("player_invisible",1);
        tell_room( environment(this_object()),
                sprintf("%s����Ӱ�����ĵ�ȥ���������ǰ��ʧ��\n",
                this_object()->query("c_name")),
                this_object() );
        write( "���������񣬿�ʼ����.\n" );
        return 1;
}
int do_visible(string arg)
{
        if( !this_object()->query("player_invisible") )
                return notify_fail("�����ڲ�û�����Ρ�\n");
        this_object()->set("player_invisible", 0);
        tell_room( environment(this_object()),
                sprintf("���ǰ��һ�󲨶���%s����ӰͻȻ���ֳ�����\n"
                        ,this_object()->query("c_name")),
                this_object() );
        write( "���������ֹͣ����.\n" );
        return 1;
}

int query_natural_life() { return 600; }

// define the cost of advance stats for Elf.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 130, "int":  70, "dex":  80,
		"con": 120, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 130, "int":  70, "dex":  80,
		"con": 120, "pie": 100, "kar": 100,
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

int query_elf_WC_bonus()
{
	object weap, ob;
	string type;

	ob = this_object();
	weap = ob->query("weapon1");
	if( !weap ) return 0;
	type = (string)weap->query("type");
	// About 15% primary weapon class bonus when level 19;
	if( type=="longblade" || type=="shortblade" )
		return (int)weap->query("weapon_class") * (int)ob->query_level()  / 120;
}

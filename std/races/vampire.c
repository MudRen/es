//#pragma save_binary

// This is a race body for Vampire, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "vampire");

	// Vampire is afraid of divine power and defend evil power.
	body->set("special_defense", ([ 
		"evil": 50, "divine": -50, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 32);

	// the natural age of Vampire.
	if( userp(body) ) body->set("natural_age", 18);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  8,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  8,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30,  5);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 8);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
*/
	// The extra command for vampire.
	add_action( "do_bloodsuck", "bloodsuck" );
}

// These functions are used for race Vampire.
// Please don't cover the functions in user.c.

int query_natural_life() { return 70; }

// define the cost of advance stats for Vampire.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str":  80, "int":  60, "dex":  80,
		"con": 140, "pie": 120, "kar": 120,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str":  80, "int":  60, "dex":  80,
		"con": 140, "pie": 120, "kar": 120,
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

int do_bloodsuck(string arg)
{
	object me, dest;

	if( !arg || arg == "" ) 
		return notify_fail("��Ҫ��˭��Ѫ��\n");

	me = this_player();
	dest = present( arg, environment(me) );
	if( !dest || !living(dest) )
		return notify_fail("����û���������\n");

	if( dest->query("no_attack") )
		return notify_fail("�㲻������һ��Ѫ��\n");

        if ( userp(dest) && ((int)dest->query_level()<5) )
                return notify_fail("�㲻���۸��͵ȼ���� !!\n");
	if ( userp(dest) && ((int)me->query_level()<5) )
		return notify_fail("��򶼻�û��Ӳ,����PK��?\n");
	
	if( dest->query_temp("be_sucked"))
		return notify_fail("��һ���������㿿������û�л�����Ѫ��\n");

	if( userp(me) && me->query_temp("bloodsuck") )
		return notify_fail("��! ��̫������Ŷ..��Ҫ����һ�°ɡ�\n");

	write(sprintf("��������%s�Ĳ���ҧȥ��",
			dest->query("c_name")));

	tell_room( environment(me), 
		sprintf("%sͻȻ����ҧ��%s�Ĳ��ӣ�", 
			me->query("c_name"), dest->query("c_name")) ,
		({ me, dest }) );

	tell_object( dest, 
		sprintf("%sͻȻ����ҧ����Ĳ��ӣ�",
			me->query("c_name")));

	dest->set_temp("be_sucked",1);

	dest->kill_ob( me );
	me->kill_ob( dest );

        me->block_attack(4);

	if ( random((int)me->query_level()*2) < (int)dest->query_level() ) {
		tell_room(environment(me),set_color("���Ǳ������� !!\n","HIY"),({}));
		me->set_temp("msg_stop_attack","(��������æ���ң��޷����� ��)\n");
		return 1;
	}

	tell_room(environment(me),set_color("��ʼ��������Ѫ !!\n","HIR"),({}));
	me->set_temp("msg_stop_attack","(����Ѫ�ʵ۴󡹣������´������˵��)\n");
	
	me->set_temp("bloodsuck", 1);

	call_out("stop_suck", 4, this_object(), dest );
	return 1;
}

void stop_suck(object me, object victim)
{
	int blood;
	if( !me ) return;
	if( !victim ) {
		call_out("bloodsuck_again", 10+2*(int)me->query_level(), me);
		return;
	}
	tell_object( me, 
		"������������մ����Ѫ���촽��һ�������ʹ��ָ���һЩ������\n");

	tell_room( environment(me), 
		sprintf("%s����������մ����Ѫ���촽��¶��һ������ı��顣\n",
			me->query("c_name")), me );
	blood = random(me->query_level());
	me->receive_healing( blood );
	victim->receive_special_damage( "evil", blood+blood );
	call_out("bloodsuck_again", 20+2*(int)me->query_level(), me);
}

void bloodsuck_again(object me)
{
	if( !me ) return;
	me->set_temp("bloodsuck",0);
}
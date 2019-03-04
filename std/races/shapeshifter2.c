//#pragma save_binary

// This is a race body for Shapeshifter, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "shapeshifter");

	// Shapeshifter has bad any special defense.
	body->set("special_defense", ([ "fire": -100, 
		"divine": -50, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 30);

	// the natural age of Shapeshifter.
	if( userp(body) ) body->set("natural_age", 1);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 7);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "����", "���", "�ұ�", "ǰ��", "����", "����",
		"����", "���", "�Ҽ�", "����", "С��", }) );
*/
	// Shapeshifter will drop all when be scared.
	remove_call_out("drop_eq");
	call_out("drop_eq", 600+random((int)body->query_level()*120));
}

// These functions are used for race Shapeshifter.
// Please don't cover the functions in user.c.

int query_natural_life() { return 70; }

// define the cost of advance stats for Shapeshifter.
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
		"feet", "shield", "cloak", "misc", "finger", "saddle",
		"tail", "kernel", "globe", });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}

// This function checks if this race can mount other animals.
int valid_mount(object ob)
{
	return (int)ob->query("mounted");
}

void drop_eq()
{
	mixed inv;

	// only user has this property.
	if( !userp(this_object()) || this_object()->query_linkdead() ) return;

	tell_object(this_object(),"ͻȻ���䡹��һ���ӱ��ᴫ��, ������һ������\n");
	inv = all_inventory( this_object() );
	if( sizeof(inv) ) {
		if( this_object()->query_temp("mounting") ) command("dismount");
		command("unsecure all");
		command("drop all");
	}
	remove_call_out("drop_eq");
	call_out("drop_eq", 600+random((int)this_object()->query_level()*60));
}
void shift_idle(object me,int time)
{
	if ( !present(target,environment(me) ) {
		tell_object(me,"���Ŀ���Ѿ����������� !!\n");
		return;
	}
		
	if ( time =< (int)target->query_level()/4 ) {
		printf("�㼯�о�����������%s !!\n",
				target->query("c_name"),target->query("c_name"));
		tell_room(environment(me),
			sprintf("%s���ڵ��ϱ���ͷ���૵����� : ����%s !! ���� %s !!\n",
			me->query("c_name"),target->query("c_name"),target->query("c_name"))
			,me );
		call_out("shift_idle",me,target,time+1);
		return ;
	}
	if ( (int)me->query_level() >= (int)target->query_level() ) {
		if ( (int)me->query("spell_points") < (int)target->query_level()*2 ) ) {
			tell_object(me,"��ľ�����������
	}
	return ;	
}
int shapeshift(string arg)
{
	object target ;
	if ( ! arg )
		return notify_fail("������γ�ʲ�᣿\n");
	if ( !target = present(arg,envoronment()) )
		return notify_fail("����û�н� "+arg+" �Ķ��� !!\n");
//	if ( !living(target) )
//		return notify_fail("
	printf("�����%s��ʼ�۾������ڤ�� ....\n",target->query("c_name"));
	tell_room(environment(),
		sprintf("%sͻȻ���۷�ֱ�Ķ���%s�����ﻹ�૵Ĳ�֪������Щʲ�� ...\n",
		this_object()->query("c_name"),target->query("c_name") ), 
		({ this_object(), target }) );
	call_out("shift_idle",2,this_object(),target,0);
	return 1;
}
int reshape()
{
	return 1;
}
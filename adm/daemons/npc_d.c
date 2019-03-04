//#pragma save_binary
#include <mudlib.h>
#include <config.h>
#include <daemons.h>
// move_player()
// query_vision() 
// die()
// kill_reward()
/*
* Move living object to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
*/ 
varargs int move_player(object me,mixed dest, mixed message, string dir)
{
	object prev;
	int res;
	
	prev = environment(me);
	if( res = me->move(dest) ) {
		tell_object(me, "( ������ԭ��.... )\n");
		return res;
	}

	if( me->query_attackers() && (int)me->clean_up_attackers() == 0) {
		me->set_temp("last_attack_skill", 0);
		//write("combat test7	!\n");
		tell_object(me, "ս��������.��\n");
	}

	if(message == "SLIENCE") return 0;
	if(message == "SNEAK") {
		call_other("/cmds/std/_look","cmd_look","");
//		me->command("look");
		return 0;
	} 

	if( !me->query("invisible") && !me->query("player_invisible")) {
		if(message == 0 || message == "") {
			if(dir && dir != "") {
				tell_room(prev, 
					(string)me->query_c_mout(dir) + "\n",
					me);
				tell_room(environment(me), 
					(string)me->query_c_min() + "\n",
					me);
			} else {
				tell_room(prev, 
					(string)me->query_c_mmout() + "\n",
					me);
				tell_room(environment(me), 
					(string)me->query_c_mmin() + "\n",
					me);
			}
		} else {
			if( pointerp(message) ) {
				tell_room(prev, 
					sprintf(message[0], me->query("c_name"))
					, me );
				tell_room(environment(me), 
					sprintf(message[1], me->query("c_name"))
					, me );
			} else {
				tell_room(prev, message + "\n", me);
				tell_room(environment(me), 
					(string)me->query_c_min() + "\n",
					me );
			}
		}
	}
//	me->set_temp("force_to_look",1);
	"/cmds/std/_look"->cmd_look();
//	me->set_temp("force_to_look",0);
	return 0;
}

int query_vision(object me)
{
	mixed *contents;
	object env;
	int loop;

	//	If there is no environment, you obviously can't see anything. :)
   if( !env = environment(me) )  return 0;
 
	// 	Check to see if user has special vision capabilities,
	//	either artificial or permanent
	if( me->query("full_vision") ) return 1;
 
	//	Check to see if user is blind, or environment prevents sight
	if(me->query("blind") || env->query("no_vision") )
		return 0;
 
	//	Check light level in the environment
	if( env->query("light")) return 1;
	if( me->query("dark_sight")) return 1;

	contents = all_inventory(env);
 
   //	Check to see if any of the environment's contents have
   //	a light source of any kind
	for(loop=0; loop<sizeof(contents); loop++)
		if(contents[loop]->check_light()) return 1; 
	return 0;
}

// kill_reward: This function is called by die() to give rewards to
// the killer who killed this_object
void kill_reward(object me,object killer)
{
	int piety, exp, align, bunus;

	if( !(exp= (int)me->query("exp_reward")) )
		exp = (int)me->query_experience() / ((int)me->query_level() + 10);

	piety = killer->query_stat("pie");

	// Piety effect: +15% to -10%
	exp += exp * (piety - (int)killer->query_level() ) / 200;

    exp += exp * (random(20)-10) / 1000;
	if( exp <= 0 ) exp = 1;

	// Add killer's align first.
	align = (int)me->query("alignment");
	if( align!=0 ) killer->add("alignment", -(align/4));

	// If killer is belong to a party, share exp.
	if( killer->query_temp("leader") ) {
		PARTY_D->share_experience(killer, exp);
	// Solo me :-(.......
	} else {
		killer->gain_experience(exp);
		tell_object(killer, 
			sprintf("��õ� %d �㾭��ֵ.��\n", exp));
	}
	return;
}


varargs void die(object me,int silent)
{
	object killer, ghost, corpse, coins, *stuff;
	mapping wealth;
	string *names, alt_corpse;
	int i, res, totcoins;

	// Define the monster's killer
	killer = me->query("last_attacker");

	// Setup corpse with monster's specifics
	alt_corpse = (string)me->query("alt_corpse");
	if( !alt_corpse ) {
		corpse = new("/obj/corpse");
		corpse->set_name(me->query("name"), me->query("c_name"));
		if( (i=me->query("weight")) > 0 ) corpse->set("weight", i);
			else corpse->set("weight",600);
		if( (i=me->query("max_load")) > 0 ) corpse->set("max_load", i);
		corpse->set("load", 0);
		corpse->set("npc",1);
		corpse->move(environment(me));
		stuff = all_inventory(me);
		for( i=sizeof(stuff)-1; i>=0 ;i-- ) {
			// Remove stuff silently. Added by Annihilator @Eastern.Stories
			if( stuff[i]->query("wielded") ) stuff[i]->unwield(1);
			else if( stuff[i]->query("equipped") ) stuff[i]->unequip(1);
			stuff[i]->move(corpse);
		}

		// Move all coins into corpse
		wealth = me->query("wealth");
		if( wealth ) {
			names=keys(wealth);
			for( i=sizeof(wealth)-1; i>=0; i-- ) {
				if( !wealth[names[i]] ) continue;
				coins = new("/std/coins");
				coins->set_type(names[i]);
				coins->set_number(wealth[names[i]]);
				me->debit( names[i], wealth[names[i]] );
				if( coins ) coins->move(corpse);
			}
		}
	} else if( alt_corpse != "NONE" ) {
		corpse = new(alt_corpse);
		if( corpse ) corpse->move( environment() );
	}

	//  Set the last_kill variable ... file_name and short of this_object

	if( killer ) {
//		killer->set("last_kill",
//			({ file_name(this_object()), query("short"), time() }));
		// NOTE: If you want to give a reward of skill points or xp or
		//  whatever to the killer, define the following function
		//  in the monster's inherit file.
//		write("die test2\n");
		kill_reward(me,killer);
	}



	// Announce the sad facts of life and non-life.
	if( !silent ) {
		tell_object(me,"������.\n");
		"/adm/daemons/combat_d_test"->report_death(me);
	}

	// If monster is inhabited, switch user to ghost body
	if(interactive(this_object())) {
		ghost = me->create_ghost();
		if( !ghost ) return;
#ifdef GHOST_START_LOCATION
		if( ghost->move(GHOST_START_LOCATION) != MOVE_OK )
			ghost->move(START);
#else
		ghost->move(START);
#endif
	}
	// Delay the remove call with a call_out to ensure all the 
	// housekeeping from above is complete.
	call_other(me,"remove", 0);
}


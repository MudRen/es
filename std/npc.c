//#pragma save_binary

// File: /std/npc.c
// The monster body is from the TMI-2 lib. Part of the bodies project and
// implemented by Watcher@TMI-2 and Mobydick@TMI-2. The code contained
// in this object is heavily based on code found in the original user.c
// and monster.c at TMI.
//
// The relevant code headers follow:
// Original author of monster.c: Huma@TMI.
// Subsequent work done by Buddha@TMI-2 and Mobydick@TMI-2.
// Original authors of user.c were Sulam@TMI and Buddha@TMI.
// Many other people have added to this as well.
// This file has a long revision history dating back to the hideous
// mudlib.n and is now probably not at all the same.
// This file is part of the TMI distribution mudlib.
// Please keep this header with any code within.
// Almost rewriteen by Kyoko@ES.

#include <config.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <move.h>
#include <money.h>
#include <priv.h>
#include <uid.h>
#include <logs.h>
#include <body.h>
#include <conditions.h>
//	object tmp;
inherit LIVING;
nosave int hb_status;
nosave int hb_tick;

int environment_check();
void move_around();
void monster_chat();
void unwield_weapon(object weapon);
void unequip_armor(object armor);
void kill_reward(object killer);

protected int create_ghost();
varargs void die(int silent);
string *path;
mapping alias;

//  Setup basic and command catch systems
void basic_commands()
{
	add_action("quit", "quit");
}

protected void init_commands()
{
	path = ({});
	add_action("cmd_hook", "", 1);

	if( link_data("wizard") ) {
		enable_wizard();
		path = NEW_WIZ_PATH;
	}
	else path = USER_CMDS;

	if( query("npc") )
		path += ({ "/cmds/std/monster" });

}

//  This function resets the monster's living_name after a user
//  shells out of the monster body.
void reset_monster()
{
	if( !interactive(this_object()) ) {
		set_living_name( query("name") );
		seteuid(getuid(this_object()));
		link = 0;
	}
}

void clear_monster()
{
	if( geteuid(previous_object())==ROOT_UID ) seteuid(0);
}

string process_input(string arg)
{
	arg = do_alias(arg);
	return arg;
}

//	Setup standard user command hook system.  This system interfaces
//	with the cmd bin system, the environment's exits, and feeling entries.
nomask protected int cmd_hook(string cmd)
{
	string file, verb;

	verb = query_verb();

	if( environment() && environment()->valid_exit(verb) ) {
		verb = "go";
		cmd = query_verb();
	}

	file = (string)CMD_D->find_cmd(verb, path);
	if( file && file != "" )
		return (int)call_other(file, sprintf("cmd_%s", verb), cmd);

//	if( environment() && environment()->query("quiet") ) return 0;
	return (int)EMOTE_D->parse(verb, cmd);
}

/*
* Move the player to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
*/
varargs int move_player(mixed dest, mixed message, string dir)
{
	object prev;
	int res;

	prev = environment();

	if( res = move(dest) != MOVE_OK ) {
		write("(������ԭ�� !!)\n");
		return res;
	}

	if( message=="SNEAK" ) {
		call_other("/cmds/std/_look","cmd_look");
//		command("look");
		return 0;
	}

	// if he is not invisible, tell other move message.
	if( !query("invisible") ) {
		// if not give move message.
		if( message == 0 || message == "" ) {
			if( dir && dir != "" ) {
				tell_room(prev,
					sprintf("%s\n", query_c_mout(dir)) ,
					this_object());
				tell_room( environment(),
					sprintf("%s\n", query_c_min()) ,
					this_object());
			} else {
				tell_room(prev,
					sprintf("%s\n", query_c_mmout()) ,
					this_object());
				tell_room(environment(),
					sprintf("%s\n", query_c_mmin()) ,
					this_object());
			}
		// if give move message.
		} else {
			if( pointerp(message) ) {
				tell_room(prev,
					sprintf(message[0], query("c_name")) ,
					this_object() );
				tell_room(environment(),
					sprintf(message[1], query("c_name")) ,
					this_object() );
			} else {
				tell_room(prev, sprintf("%s\n", message), this_object());
				tell_room( environment(),
					sprintf("%s\n", query_c_min()) ,
					this_object());
			}
		}
	}

	// Ok. let he look the room.
	set_temp("force_to_look", 1);
		call_other("/cmds/std/_look","cmd_look");
//	command("look");
	set_temp("force_to_look", 0);

	//	Follow/track mudlib support
/*
	if( !query("no_follow") && environment() != prev )
		all_inventory(prev)->follow_other(this_object(), environment(), dir);
*/
	return 0;
}

//	If the monster body is inhabited by a user, give the
//	monster's living hash table name as that of the user.
void init_setup()
{
	if( !query_link() )  return 0;

	set_heart_beat(1);
	seteuid(getuid(this_object()));
	set_living_name( link_data("name") );

	basic_commands();
	init_commands();
}

void create()
{
	alias = ([ ]);
	seteuid(getuid());
	set("npc", 1, LOCKED);
	set_level(1);
//	set("autosave", 500);
	set("max_load", "@@query_max_load");
//	set("weight", 600);
	set("short", "@@query_short");
	set("vision", "@@query_vision");
//	set("gender", "neuter");
//	set("languages", ([ "common" : 100 ]) );
	set("no_attack", "@@stop_attack");
	set_heart_beat(1);
//	set("PATH", ({ "/cmds/std", "/cmds/std/monster", }));
	set("max_hp",5);
        HEAL_HP->apply_effect(this_object(),  5,  1);
	enable_commands();
	basic_commands();
	init_commands();
}

void remove()
{
	mixed *inv;
	int loop;

	inv = all_inventory(this_object());
	for( loop=sizeof(inv)-1; loop>=0; loop-- )
		if( inv[loop]->query("prevent_drop") ) inv[loop]->remove();

	CMWHO_D->remove_user(this_object());
	if( link ) link->remove();
	living::remove();
}

int quit(string str)
{
	object ob;
	int i, j;

	if( str ) return notify_fail("Quit what?\n");

#ifdef LOGOUT_MSG
	tell_object(this_object(), LOGOUT_MSG);
#endif

#ifdef QUIT_LOG
	if( this_object() && interactive(this_object()) )
	log_file( QUIT_LOG,
		sprintf("Monster %s controlled by %s quit from IP:%s Time:%s.\n",
			query("name"), link_data("name"),
			query_ip_name(this_object()), extract(ctime(time()), 4, 15)) );
#endif

	// If the connection object is somehow missing. Just remove the monster.
	if( !query_link() ) {
		if( interactive(this_object()) ) remove();
		reset_monster();
		return 1;
	}

	ob = new(OBJECT);			// Temporary body

	query_link()->set("tmp_body", ob);
	query_link()->switch_body();
	ob->remove();

	query_link()->remove();
	reset_monster();

	return 1;
}

void heart_beat()
{
	object obj;
	string dir;

	if (hb_tick< MAX_TICK) {
		hb_tick++;
		return;
	} else hb_tick = 0;

	// If we're chasing someone, better go after him.
	if( dir = this_object()->query("in_pursuit") ) {
		call_other("/cmds/std/_go","cmd_go",dir);
//		command( sprintf("go %s", dir) );
		if ( obj = (object)this_object()->query("pursued")) {
		if( present( obj, environment()) ) {
			tell_object(obj,
				sprintf("%s�ּ���������!\n", query("c_name")));
			obj->kill_ob(this_object());
		}
		delete("in_pursuit");
		delete("pursued");
		}
	}

	continue_attack();
	if( query("moving")==1 ) move_around();
	if( random(100) < query("chat_chance") ) monster_chat();

	unblock_attack();

	// this will call all conditions he has.
	heal_up();

	//  If no-one is around and fully healed, shut down the heartbeat
	if( !environment_check() && query("hit_points") >= query("max_hp") ) {
		// if we still have spell points to heal.....
//		if( query("max_sp") && query("max_sp") > query("spell_points") )
//			return;
		// because force points won't heal up, so I tune off this now.
//		if( query("max_fp") && query("max_fp") > query("force_points") )
//			return;

		// If we're whanging on someone, best not to shut it down... :)
		if( sizeof(attackers) ) return;
		set_heart_beat(0);
		hb_status = 0;
	}
}

//  This function allows monsters to talk or give environmental sounds.
void monster_chat()
{
	mixed *chats;
	int msg;

	if( attackers && sizeof(attackers) ) chats = query("att_chat_output");
	else chats = query("chat_output");

	if( !chats || !sizeof(chats) ) return;

	if( environment() ) {
		msg = random(sizeof(chats));
		tell_room( environment(), chats[msg], this_object() );
	}
	return;
}

varargs protected void die(int silent)
{
	object killer, ghost, corpse, coins, *stuff;
	mapping wealth;
	string *names, alt_corpse;
	int i, res, totcoins;

	// Define the monster's killer
	killer = query("last_attacker");
	init_attack();

	// Setup corpse with monster's specifics
	alt_corpse = (string)query("alt_corpse");
	if( !alt_corpse ) {
		corpse = new("/obj/corpse");
		corpse->set_name(query("name"), query("c_name"));
		if( (i=query("weight")) > 0 ) corpse->set("weight", i);
			else corpse->set("weight",600);
		if( (i=query("max_load")) > 0 ) corpse->set("max_load", i);
		corpse->set("load", 0);
		corpse->set("npc",base_name(this_object()));
		corpse->move(environment());
		stuff = all_inventory(this_object());
		for( i=sizeof(stuff)-1; i>=0 ;i-- ) {
			// Remove stuff silently. Added by Annihilator @Eastern.Stories
			if( stuff[i]->query("wielded") ) stuff[i]->unwield(1);
			else if( stuff[i]->query("equipped") ) stuff[i]->unequip(1);
			stuff[i]->move(corpse);
		}
		corpse->add("weight",corpse->query("load"));
		// Move all coins into corpse
		wealth = query("wealth");
		if( wealth ) {
			names=keys(wealth);
			for( i=sizeof(wealth)-1; i>=0; i-- ) {
				if( !wealth[names[i]] ) continue;
				coins = new(COINS);
				coins->set_type(names[i]);
				coins->set_number(wealth[names[i]]);
//				debit( names[i], wealth[names[i]] );
				if( coins ) coins->move(corpse);
			}
			delete("wealth");
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
                   killer->add("NKS",1) ;
				   //write("die test3\n");
		kill_reward(killer);
	}

	// Announce the sad facts of life and non-life.
	if( !silent ) {
		write("������.\n");
		COMBAT_D->report_death();
	}

	// If monster is inhabited, switch user to ghost body
	if(interactive(this_object())) {
		ghost = create_ghost();
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
	call_out("remove", 0);
}

// kill_reward: This function is called by die() to give rewards to
// the killer who killed this_object
void kill_reward(object killer)
{
	int piety, exp, align, bunus;

	if( !(exp= (int)query("exp_reward")) )
		exp = query_experience() / (query_level() + 10);

	piety = killer->query_stat("pie");

	// Piety effect: +15% to -10%
	exp += exp * (piety - (int)killer->query_level() ) / 200;

    exp += exp * (random(20)-10) / 1000;
	if( exp <= 0 ) exp = 1;

	// Add killer's align first.
	align = (int)query("alignment");
	if( align!=0 ) killer->add("alignment", -(align/4));

	// If killer is belong to a party, share exp.
	if( killer->query_temp("leader") ) {
		PARTY_D->share_experience(killer, exp);
	// Solo me :-(.......
	} else {
		killer->gain_experience(exp);
		//write("exp test!\n");
	tell_object(killer,
		sprintf("��õ� %d �㾭��ֵ��\n", exp));
	}
  if(explode(base_name(this_object()),"/")[0]== "u")
      if(!wizardp(killer))
       log_file("CHECK",killer->query("c_name")+" ɱ��"+query("name")+"["+
       base_name(this_object())+"] �õ� "+exp+" ����"+" ["+extract(ctime(time()),4,15)+"]\n");
        return;
}

// These are the hooks for aggressive and killer monsters.
// If a monster turns on the "aggressive" property, then if they receive
// a message of the form "Foo enters" then they attack Foo. This is done
// in receive_messages. Players can get past these monsters by sneaking
// into the room or being invisible. Also, they don't attack if they enter
// the player's environment, only if the player enters theirs. Monsters
// which turn on the "killer" property will attack any player that triggers
// the monster's init. It can't be fooled by invis or sneaking, and it will
// attack you if it moves into your room. Moving killer monsters can be
// pretty nasty things.
// Add random for "aggressive" attack, by Kyoko.
void relay_message(string mclass, string str)
{
	string name, direction, tmp;
	object victim;

	if( !str || str == "" ) return;
	if( sscanf(str,"%s(%s)���˹�����", tmp,name)==2 ) {
		name = lower_case(name);
		victim = present(name, environment(this_object()));
		if( !victim || victim->query("npc") || victim->query("no_attack") )
			return;
/*
		if( random(100)+1 < query("fearsome") ) {
		  	tell_object(victim,
		  		sprintf("��ĳ��־�����%s��\n", query("short")));
			move_around();
			return;
		} else
*/
		if( query("aggressive") && !victim->query("ghost") )
			// if victim is too lucky to be attacked, skip it, by Kyoko.
			if( random(100) > (int)victim->query_stat("kar") ) {
					tell_object(victim, ( (tmp=query("c_killer_msg")) ?
						sprintf("%s\n", tmp):
						sprintf("ͻȻ���㷢�� %s �����������������������....\n", query("short")) ) );
				kill_ob(victim);
			} else {
				tell_object(victim,
					sprintf("��о� %s �ƺ�����������Ŀ�����...\n", query("short")));
			}
	}

	if( query("pursuing") && sscanf(str,"%s(%s)��%s���뿪��", tmp,name, direction)==3) {
		name = lower_case(name);
		victim = find_living(name);
		if( victim && attackers && member_array(victim, attackers) > -1 ) {
			set("in_pursuit", to_chinese(direction));
			set("pursued", victim);
		}
	}
}

void init()
{
	int my_dex,opp_dex,my_kar,opp_kar;
	object ob;
	string tmp;

	ob = this_player();
	if ( ob->query_temp("hidding")) {
		my_dex = query_stat("dex");
		opp_dex = ob->query_stat("dex");
		my_kar = query_stat("kar");
		opp_kar = ob->query_stat("kar");
		if ( !query_temp("detect_hide")) {
			if (random((my_kar+my_dex)/4+opp_kar+opp_dex) < (opp_kar+opp_dex))
			return;
		} else
		if (random(my_kar+opp_kar+(my_dex/2)) < opp_kar)
			return;
	}
	//  If object is not a monster and is visible...think about attacking.
	if( !ob->query("npc") && !ob->query("ghost") &&
		!ob->query("no_attack") && visible(ob) ) {
		if( will_attack && member_array(ob, will_attack) != -1 ) {
			will_attack -= ({ ob });
			kill_ob( ob );
			if( !this_object()->catch_huntee(ob) )
				tell_room( environment(),
					sprintf("%s�е�: �ɶ������㣡\n", query("c_name")) ,
					this_object() );
		} else
		if( query("killer") && kill_ob(this_player()) ) {
				write( (tmp=query("c_killer_msg"))?
					sprintf("%s\n", tmp):
					sprintf("ͻȻ���㿴�� %s ������˹���!\n", query("c_name")) );
		}

 		// If heartbeat is turned off ... turn it back on.
		if( !hb_status ) {
			hb_status = 1;
			set_heart_beat(1);
		}
	}
}

// This lets a pursuing monster chase you. It's call_out'd from
// relay_message.
int query_monster()
{
	return 1;
}

int query_npc()
{
	return 1;
}

int query_hb_status()
{
	return hb_status;
}

void move_around()
{
	mapping doors, exits, tmp, patrol;
	mixed *dirs, foo;
	int i;

	// If we have no environment, then stop moving around. Done for two
	// reasons. First, there's nowhere to go anyway, so save CPU. Second,
	// this stops the callout loop in master copies of objects.
	// We also shut it down if there's no exits: same logic.

	this_object()->set("moving",-1);

	if( !environment(this_object()) ||
		!( exits= environment(this_object())->query("exits")) )
	{
		this_object()->set("moving",0);
		return;
	}
	// make moving mob can be stopped by set moving 0, by Kyoko.
	if( this_object()->query("moving") != 0 )
		call_out("move_around", this_object()->query("speed") );

	// If we're in combat, probably oughta stay here.
	if( sizeof(attackers) ) return;
	// If we have a patrol pattern to follow, get the direction from
	// that. If not, pick a direction at random.
	if( patrol = this_object()->query("patrol") ) {
		i = this_object()->query("patrol_step");
		foo = patrol[i];
		i++;
		if ( i == sizeof(patrol))
			i = 0;
		this_object()->set("patrol_step",i);

	} else {
		dirs = keys(exits);
		foo = dirs[random(sizeof(dirs))];
	}

	doors = environment(this_object())->query("doors");
	if( doors && sizeof(doors) && doors[foo] &&
		doors[foo]["status"] != "open" ) {
		call_other("/cmds/std/_open","cmd_open",(string)foo+" door");
//		command(sprintf("open %s door", (string)foo));
		return;
	}
		call_other("/cmds/std/_go","cmd_go",(string)foo);
//	command(sprintf("go %s", foo));
}

void wield_weapon(mixed weap)
{
	object foo, weapon;

	if( objectp(weap) ) weapon = weap;
	else if( stringp(weap) ) {
		weapon = new(weap);
		weapon->move(this_object());
	} else return;
	foo = query("weapon1");
	if( foo ) unwield_weapon(foo);
	if( !weapon ) return;
	set("weapon1", weapon);
	weapon->wield();
}

void wield_weapon2(mixed weap)
{
	object foo, weapon;

	if( objectp(weap) ) weapon = weap;
	else if( stringp(weap) ) {
		weapon = new(weap);
		weapon->move(this_object());
	} else return;
	foo = query("weapon2");
	if( foo ) unwield_weapon(foo);
	if( !weapon ) return;
	set("weapon2", weapon);
	weapon->wield();
}

void equip_armor(mixed obj)
{
	string type;
	object foo, armor;

	if( objectp(obj) ) armor = obj;
	else if( stringp(obj) ) {
		armor = new(obj);
		armor->move(this_object());
	} else return;
	if( !armor ) return;
	type = armor->query("type");
	foo = query("armor/"+type);
	if( foo ) unequip_armor(foo);
	if( !armor ) return;
	armor->equip();
	calc_armor_class();
}

void unwield_weapon( object weapon )
{
	if( weapon==(object)query("weapon1") ) set("weapon1", 0);
	else if( weapon==(object)query("weapon2") ) set("weapon2", 0);
	else return;
	weapon->unwield();
}

void unequip_armor(object armor)
{
	armor->unequip();
}

//  This function checks to see if there are any players present in
//  the monsters room, so heartbeat can be turned off periodically.
int environment_check()
{
	if( interactive(this_object()) )  return 1;

	if( environment() )
		return sizeof( filter_array(all_inventory(environment()), "filter_env",
			this_object()) );
	return 0;
}

protected int filter_env(object obj)
{
	return ( interactive(obj) && visible(obj, this_object()) );
}

// The following are some macro functions for initializing monster.
// By Annihilator@Eastern.Stories 1-24-94
void set_natural_armor( int ac, int db )
{
	ob_data["natural_armor_class"] = ac;
	ob_data["natural_defense_bonus"] = db;
//	caluate ac db for monsters that no wear eqs
//					add by Iris 1/20/95
	calc_armor_class();
}

void set_natural_weapon( int wc, int min_dam, int max_dam )
{
	ob_data["natural_weapon_class1"] = wc;
	ob_data["natural_min_damage1"] = min_dam;
	ob_data["natural_max_damage1"] = max_dam;
}

void set_natural_weapon2( int wc, int min_dam, int max_dam )
{
	ob_data["natural_weapon_class2"] = wc;
	ob_data["natural_min_damage2"] = min_dam;
	ob_data["natural_max_damage2"] = max_dam;
}

/* EOF */

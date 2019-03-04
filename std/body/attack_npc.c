//#pragma save_binary

// Program: /std/body/attack.c
// Written mostly by Buddha@TMI
// Originally based on the attack.c found in the mudlib.n,
// many structural similarites may remain.
// It is is a part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Much work was done in December of 1991.
// revised 2-16-92 by Buddha
// revised again 3-1-92 by Buddha
// Rewritten to remove the LOC, and to update it for mudlib 0.9, by
// Mobydick@TMI-2, 9-21-92
// Added some stuff to make monsters remember and attack old opponents.
// Mobydick, 2-3-93.
// Added receive_damage() and receive_healing() systems, Watcher 3-27-93
// Basic structure:
// The function kill_ob is used to initiate combat. The kill command calls
// it in any monster or player entering combat, as do the combat spells and
// other nastiness. It also turns on a monster's heartbeat if that is
// necessary.
// The heart_beat calls the continue_attack function. This function checks
// to see if the monster is dead and if so, starts the death sequence. It
// then checks the list of current opponents and removes any that are dead
// or otherwise out of the MUD. Opponents that have left the room are moved
// onto the "will_kill" list. It then checks to see if spellcasting or
// other activity has blocked the attack. If not, it calls execute_attack
// which does the actual attack against the first attacker on the list.
// Ruby fix at '94/11/24  -- 1. receive_damage . 2. block attack 3.continue attack about msg_stop_attack

#include <mudlib.h>
#include <daemons.h>
#include <martial.h>
#include <conditions.h>

inherit CONTAINER_OBJECT;

// wombled by buddha
static object *attackers, *will_attack, current_attacker; 
static int any_attack, now_attack_skill_type;
 static int cond_tick;
static string *c_vb, *c_limbs;

// Prototypes for things that come in through the body object.
// These function will be defined other places.
int query_stat(string stat);
varargs static void die(int silent);

void run_away();
int kill_ob (object victim);
void set_c_verbs(string *verbs);
void set_c_limbs(string *lmbs);
string get_c_verb();
string get_c_limb();
void cease_all_attacks();
void continue_attack();
int tactic_function(object victim);

// This function handles the damage calls from battle. It only accepts
// positive damage calls. receive_healing() should be used for healing.
int receive_damage(int damage)
{
	int hits;
	object act_ob;

	hits = query("hit_points");
	act_ob = previous_object();
	if( act_ob && living(act_ob) ) set("last_attacker", act_ob);

	if( damage <= 0 || hits < 1 )
		return 0;

	hits -= damage;

	set( "hit_points", hits );

 	return 1;
}

int receive_special_damage(string type, int damage)
{
	int dam;
	object act_ob;

	if( damage <= 0 || query("hit_points") < 1 )
		return 0;

	damage -= damage * (int)this_object()->query_special_defense(type) / 100 ;

	damage -= random((int)query("defense_bonus"));

	if( damage < 1 ) return 1;

	receive_damage(damage);

 	return 1;
}

// This function handles the healing calls from spells. It only accepts
// positive healing calls.  receive_damage() should be used for damage.
int receive_healing(int healing)
{
	int heal;

	if( healing <= 0 || query("hit_points") < 1 )
		return 0;
		
	heal = query("hit_points") + healing;
	if( heal > query("max_hp") ) heal = (int)query("max_hp");
	set("hit_points", heal);
	return 1;
}

// This function updates the object's AC. It got moved out of the
// player object so monsters could have it too.
int calc_armor_class()
{
	return 0;
}

// This function updates the object's bare-handed weapon_classes.
void calc_weapon_class()
{
	
}

// This function is used to prevent a player from attacking for a time.
// Called by the wield command, the various spells, other places. Anything
// a players does that should interfere with his combat should call this.
void block_attack(int t)
{
	// If we're not in combat, then don't bother.
	if( !any_attack ) return;
	add("stop_attack", t/2);
}

// This is called in the heart_beat to decrease the blocking time.
void unblock_attack()
{
	int i;

	i = query("stop_attack")-1;
	if( i > -1 ) set("stop_attack", i);
	else set_temp("msg_stop_attack", 0);
}

// This function returns the object we want to attack.
object query_attacker()
{
    int number;

	if( !attackers || (number=sizeof(attackers)) < 1 ) return 0;
	number = random(number);
	return attackers[number];
}


// This is the 'kill' command. If the victim is not attacked yet,
// then it is entered first into the list of victims. If it is already
// in the list, then it is moved to the first entry.

int kill_ob(object victim)
{
	int i;

	// This make race body can override old calc_weapon_class(), by Annihilator
	// Need?? Kyoko.
	if ( !victim ) return 0;
	this_object()->calc_weapon_class();
	
	if( !attackers ) attackers = ({});;
	if( member_array(victim, attackers)>=0 ) return 0;

	// creature cannot invis while fighting....
	if ( query_temp("hidding") ) {
		this_object()->set_temp("hidding",0);
		this_object()->set_temp("hide_score",0);
	}

	if( this_object()->query("player_invisible") ) {
		this_object()->set("player_invisible", 0);
		tell_room(environment(),sprintf("���ǰ��һ�󲨶���%s����ӰͻȻ���ֳ�����\n",this_object()->query("c_name")),
			  this_object());
	}
	attackers += ({ victim });
	any_attack++;
	set_heart_beat(1);
	victim->kill_ob(this_object());
	return 1;
}

// This is a default heart_beat for living objects. There's a player heart_beat
// in user.c and a monster heart_beat in monster.c, both of which should
// override this one.
void heart_beat()
{
	unblock_attack();
	continue_attack();
}

// Call this to erase the list of opponents to attack. This will NOT stop
// them from attacking you again...  ;)
void cease_all_attacks()
{
	attackers = ({});
	any_attack = 0;
}

// Call this function to remove a specific user from the attack array.
int remove_attacker(object obj)
{
	if( member_array(obj, attackers) != -1 ) attackers -= ({ obj });
	return 1;
}

// This function returns the current target we want to hit with max possiblity
// if there is one. The "current target" could be in another room, or dead, 
// and not cleaned out of the list yet, so be reasonably careful with this.
object query_current_attacker()
{
	if( sizeof(attackers) == 0 )
		return 0;
	else
		return current_attacker;
}

// This function returns the whole attackers list. Same caveat as above.
// note, linkdead players are skipped.
object *query_attackers()
{
	if( !attackers || sizeof(attackers)==0 ) return 0;
	return attackers;
}

// This lets a wimpy player or monster run away. Buddha got this part
// working for the case of rooms with no exits. (Bad sign for the wimp.)
void run_away()
{
	int wimpy;
	string direction;
	mapping womble;

	womble = environment(this_object())->query("exits");
	if( !womble ) return;
	direction = query("wimpydir");
	if( !direction || !womble[direction] )
 		direction = keys(womble)[random(sizeof(womble))];
	tell_object( this_object(),
		sprintf("�㳢���� %s ������...\n", to_chinese(direction)));
	this_object()->force_me(sprintf("go %s", direction));
	return;
}

// This function is called in every heart_beat, you must do as less thing
// as can in the function and those it calls. Most living has several
// invisible conditions such as _heal_hp and _heal_sp, they are called
// here.
// Cleaned up by Annihilator@Eastern.Stories (94/09/21)
void heal_up()
{
	mapping conditions;
	string *conds;
	int i;
	
	cond_tick++;
	if( cond_tick > 100000 ) cond_tick = 0;

	conditions = (mapping)query("conditions");
	if( !conditions || sizeof(conditions)<1 ) return;
	conds = keys(conditions);
	for( i=0; i<sizeof(conds); i++ ) {
		if( sizeof(conditions[conds[i]]) < 1 ) continue;
		if( cond_tick % conditions[conds[i]][0] ) continue;
		call_other( CONDITION_MASTER(conds[i]), "effect", this_object() );
	}
}

// The set_verbs and get_verb functions are used by combat daemon to get
// strings of the verb when the living attacks.

void set_c_verbs(string *verbs)
{
	c_vb = verbs;
}

string get_c_verb()
{
	int i;
	object weapon, weapon1, weapon2;
	string skill, msg;

	if( skill = query("attack_skill") ) {
		if( now_attack_skill_type )
			msg = (string)ATTACK_SKILL(skill)->query_attack_msg(this_object(), current_attacker, now_attack_skill_type);
		if( msg ) return msg;
	}
	
	weapon1 = query("weapon1");
	if( weapon1 ) return (string)weapon1->get_c_verb();
	
	weapon2 = query("weapon2");
	if( weapon2 ) return (string)weapon2->get_c_verb();
	
	if( !c_vb || !pointerp(c_vb) || !(i=sizeof(c_vb)) ) return 0;
	else return c_vb[random(i)];
}
 
// The set_limbs and get_limb functions are used by combat daemon to get
// strings of the limbs that the living can be hit in combat.

void set_c_limbs(string *lmbs)
{
	c_limbs = lmbs;
}

string get_c_limb()
{
	int i;

	if( !c_limbs || !pointerp(c_limbs) || !(i=sizeof(c_limbs)) ) return 0;
	else return c_limbs[random(i)];
}

int valid_protect(object obj)
{
	if( obj && present(obj, environment(this_object())) && 
	    ((int)obj->query("hit_points") >= 0) && (!obj->query("linkdead")) )
		return 1;
	return 0;
}

varargs void execute_attack(int second_attack)
{

	int wc, dam, str, parry_apply, dex, ac, db;
	int hit_chance, pene_chance, old_damage, damage, n;
	int my_kar, opp_kar, extra_damage;
	int parry_skill, block_skill, dodge_skill;
	object *prots, tmp, weapon, shield, victim;
	string func;

	if( query_temp("block_command")==1 ) return;
	if( !attackers ) return;
	
	// set the random hit, updated by Kyoko.
	victim = query_attacker();

	if( !victim ) return;

	prots = victim->query_temp("protectors");
	if( pointerp(prots) && sizeof(prots)>0 ) {
		// Get rid of all ineligible protectors: dead, net-dead or not present.
		prots = filter_array(prots, "valid_protect", this_object());
		// If there are eligible protectors, then move the protector to the top
		// of the list, adding him if needed.
		if( sizeof(prots) ) {
			tmp = prots[random(sizeof(prots))];
			n = this_object()->query_stat( "int" );
			if( random(n*5) < (int)tmp->query_skill("defend") ) {
			  victim = tmp;
			  tmp->kill_ob(this_object());
			}
		}
	}

	// use for get_c_verbs. added by Kyoko.
	current_attacker = victim;

	// Calculate basic values
	weapon = (object)query( second_attack? "weapon2": "weapon1" );
	str	= this_object()->query_stat("str");
	wc	= (int)query( second_attack? "weapon_class2": "weapon_class1");

	dam	= (int)query( second_attack? "min_damage2": "min_damage1");
	dam += random( (int)query( second_attack? "max_damage2": "max_damage1") - dam );

	dex	= (int)victim->query_stat("dex");
	ac	= (int)victim->query("armor_class");
	db	= (int)victim->query("defense_bonus");
	my_kar = this_object()->query_stat("kar");
	opp_kar = (int)victim->query_stat("kar");

	hit_chance = 50 + wc*2 - dex*3;
	pene_chance = second_attack? 40: 50 + str*3 + wc/2 - ac;
	old_damage = dam - db/2 - random(db/2);
    damage = old_damage;
    
	// The hit chance is constrained to be between 
	// 5 and 95 percent. But penetrate chance is not constrained.
	if( hit_chance<5 ) hit_chance = 5;
	if( hit_chance>95 ) hit_chance = 95;
	if( pene_chance<5 ) pene_chance = 5;

	// If hit and penetrate, minimum damage is 1
	if( damage < 1 ) damage = 1;

	// Check if the victim can perform a defense reaction like parry, block ...

	parry_skill = (int)victim->query_skill("parry");
	block_skill = (int)victim->query_skill("block");
	dodge_skill = (int)victim->query_skill("dodge");

		// Modify as victims combat type, added by Kyoko.
		// Cleaned up a bit by Annihilator.
	if( func = (string)query("tactic") ) {
		damage += (int)TACTIC(func)->modify_damage(damage, 0);
		parry_skill += (int)TACTIC(func)->modify_parry(parry_skill,0);
		block_skill += (int)TACTIC(func)->modify_block(block_skill,0);
		dodge_skill += (int)TACTIC(func)->modify_dodge(dodge_skill,0);
	}

	if( func = (string)victim->query("tactic") ) {
		damage += (int)TACTIC(func)->modify_damage(damage,1);
		parry_skill += (int)TACTIC(func)->modify_parry(parry_skill,1);
		block_skill += (int)TACTIC(func)->modify_block(block_skill,1);
		dodge_skill += (int)TACTIC(func)->modify_dodge(dodge_skill,1);
	}
        
	// Two-handed weapons are more difficulty to parry or block.
	if( weapon && weapon->query("nosecond") ) {
		parry_skill /= 2;
		block_skill /= 2;
	}

		// Parry a attack? check victim's skill and parryed or not.
		// Modify the possible error of weapon ( attacker's or
		// victim's ). Done by Kyoko.
	if( parry_skill && (tmp =victim->query("weapon1")) ) {
	    parry_apply = str - (int)victim->query_stat("str");
		if( random( parry_skill/2 + hit_chance + parry_apply ) > hit_chance ) {
			damage = -2;
			// New weapon apply, called in the weapon when
			// its owner parried with it. Added by Annihilator.
			tmp->done_parry( this_object(), victim );
		}
	}

		// Block a attack? check victim's skill and blocked or not.
		if( block_skill && (tmp =victim->query("armor/shield")) ) {
			n = (int)tmp->query("armor_class");
			if( random( block_skill/4 + hit_chance ) > hit_chance - n ) {
				damage = -3;
				// New armor apply, called in the shield when
				// its owner blocked with it. Added by Annihilator.
				tmp->done_block( this_object(), victim );
			}
		}
		
		// ��������к� ??         rate : 34%        added by almuhara.
		if( (parry_apply = (int)victim->query_skill("unarmed-parry")) && (tmp = query("weapon1"))
		    && !(tmp = victim->query("weapon1")) ) {
			n = (int)this_object()->query_stat("dex")*2 - dex;
			if( random( parry_apply/2 + hit_chance - n/2 ) > hit_chance ) 
				damage = -5;
		}
		
		// Chech if victim can dodge our attack.
		if( damage > 0 ) {
			if( random( dodge_skill/2 + hit_chance + opp_kar ) > hit_chance )
				damage = -4;
		} 
		

	// Do we hit?
	if( damage > 0 && random(100)<hit_chance ) {
		// Do we penetrate ?
		if( random(100)<pene_chance ) {
			// Hit and penetrate, give the damage and grant some exp.
			if( victim ) victim->receive_damage( damage );
			// check special attack function of weapon......
			if( weapon ) {
				if( random(100) < (int)weapon->query("bleeding") )
					BLEEDING->apply_effect( victim, str/2, str/6 );

				extra_damage += (int)weapon->weapon_hit( victim, damage );

				if( query("aiming_loc") ) 
					extra_damage += (int)AIM_DAEMON->aim_target( this_object(), victim );
			}
			// Check special attack for inner force, a player need set 
			// enable_inner_force flag then we do it.
			if( query("force_points") )
				extra_damage += (int)FORCE_DAEMON->force_apply( this_object(), victim, weapon );
		} else
			// We failed to penetrate opponent's strong armor ....
			damage = 0;
	}
	// We missed.
	else if( damage > 0 ) damage = -1;

	// If we are not wielding any weapon, we can't be parryed or blocked.
	if( !weapon && damage < 0 ) damage = -1;

	// Report the fight to us, opponent and others.
	if( (damage > 0) && extra_damage ) damage += extra_damage;
	COMBAT_D->report_combat( this_object(), victim, damage, weapon );

	// If victim die remove it from attackers.
	if( (int)victim->query("hit_points") < 1 )
		remove_attacker( victim );

	// If we are attacking with second hand/weapon, we have done enough.
	if( second_attack ) return;

	// If we are wielding two weapons, make another attack now.
	if( query("weapon2") && query_attackers() )
		execute_attack(1);

	// Do we lucky enough to take chance and make an extra attack ?
	if( victim && old_damage > 0 && damage > 0
	    && (int)victim->query("hit_points") > -1 
	    && random( my_kar + opp_kar + 40 ) < my_kar ) {

		// Do we hit ?
		if(random(100)<hit_chance) {
			// Do we penetrate ?
			if( random(100) < pene_chance )
				victim->receive_damage( old_damage );
			else old_damage = 0;
		} else old_damage = -1;

		write( "��һ�����֣�����������\n");

		tell_room( environment(), 
			sprintf("%sһ�����֣�ץס�����������!\n", query("c_name")) ,
			this_object() );

		if( (int)victim->query("hit_points") < 1 )
			remove_attacker( victim );
		COMBAT_D->report_combat( this_object(), victim, old_damage, weapon );
	}
}

 int clean_up_attackers()
{
	mixed *attackers_tmp, *will_attack_tmp;
	int i, j=0, k=0, max, forgetful;

	forgetful = query("forgetful");

        attackers_tmp = ({});

        for( i=0; i < sizeof(attackers); i++ ) {
		// If he's dead, then forget about him entirely.
		if( !attackers[i] || !living(attackers[i]) ) continue;

		// If he's a ghost, we've done enough to him already :)
		if( attackers[i]->query("ghost") ) continue;

		// If he's not here, then we consider two cases.
		if( environment(attackers[i]) != environment(this_object()) ) {
			// If this is a monster who is not forgetful, then add this
			// attacker to the will_attack_tmp, which later will add to
			// will_attack, the list of objects to be attacked on sight.
			// If a forgetful monster, then forget about him.
			if ( !forgetful ) {
				if ( !will_attack ) 
					will_attack = ({attackers[i]}) ;
				else will_attack += ({attackers[i]});
			}
			continue;
		}

		// If we get this far, then we still want to be attacking him
			attackers_tmp += ({ attackers[i] });
	}

	attackers = attackers_tmp;
	if ( sizeof(attackers) == 0 ) any_attack=0;
	return any_attack;
}

// Continue_attack is called from heart_beat in monster.c and user.c.
// here is where we can try to see if we're dead or in combat.
void continue_attack()
{
	string msg ;
	// Check if this object has just died. if so, do the death stuff.
	if( query("hit_points") < 1 && !query("ghost") ) {
		die();
		return;
	}

	// If there's no one to attack, then we are finished.
	if( any_attack == 0 ) return;
	// Call the clean_up_attackers function to see who's left. If it returns
	// 0, then there's no one left.
	if( clean_up_attackers() == 0 ) {//write("combat test1!\n");
		tell_object(this_object(),"ս��������.\n"); /* No attackers in the room */
		any_attack = 0;
		return;
	}

	// Check to see if the monster is doing something that prevents him from
	// making an attack.
	if( query("stop_attack") > 0 ) {
                if( msg = query_temp("msg_stop_attack") )
                        write( msg );
                else write (
                        "( �㻹û�������һ��������ʧȥһ�ι������� )\n");
		return;
	}

	// Check to see if we're under wimpy, and if so, run away.
	if( query("hit_points") < query("wimpy") ) 
		run_away();
	
	if( !query_attackers() ) return;
	// Check if we have tactic_function and call it.
	if( tactic_function( attackers[0] ) ) return;

	execute_attack();
}

// You can override this function to make special attacks
int tactic_function(object victim)
{
	string tactic;

	if( stringp(tactic=query("tactic_func")) )
		return call_other( this_object(), tactic, victim );
	else return 0;
}

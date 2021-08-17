//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>
#include <martial.h>
#include <conditions.h>
inherit CONTAINER_OBJECT;

nosave object *attackers, *will_attack, current_attacker;
nosave int any_attack, now_attack_skill_type;
nosave int cond_tick;
nosave string *c_vb, *c_limbs;

void run_away();
int kill_ob (object victim);
void set_c_verbs(string *verbs);
void set_c_limbs(string *lmbs);
string get_c_verb();
string get_c_limb();
void cease_all_attacks();
void continue_attack();
int tactic_function(object victim);
//add by cach 2001.5
//protected void die();
varargs protected void die(int silent);

int gain_experience(int exp);

/*
mixed query(string what);
mixed query_temp(string what);
void add(string what, mixed arg);
void set(string what, mixed arg);
void set_temp(string what, mixed arg);
void die();

*/
//end of add
// This function updates the object's AC. It got moved out of the
// player object so monsters could have it too.
int calc_armor_class()
{
    mapping armor, extra_dbs, extra_acs;
    int i, equip_level, armor_ac, extra_ac, ac;
    int armor_db, extra_db, db, max_db, max_extra_db;
    mixed *types, *extra_db_types, *extra_ac_types;

    ac = (int)query("natural_armor_class");
    db = (int)query("natural_defense_bonus");
    extra_dbs = query_temp("extra_db");
    extra_acs = query_temp("extra_ac");

    if( extra_dbs && mapp(extra_dbs) ) {
        extra_db_types = keys(extra_dbs);
        for( extra_db=0, i=sizeof(extra_db_types)-1; i>=0; i-- )
            extra_db += extra_dbs[extra_db_types[i]];
    }

    if( extra_acs && mapp(extra_acs) ) {
        extra_ac_types = keys(extra_acs);
        for( extra_ac=0, i=sizeof(extra_ac_types)-1; i>=0; i--)
            extra_ac += extra_acs[extra_ac_types[i]];
    }

    armor = query("armor");
    if( !userp(this_object()) && !ac && !db && !armor ) {
        ac = (int)this_object()->query_level() * 5;
        db = (int)this_object()->query_level() * 2;
    } else if( armor && mapp(armor) ) {
        types = keys(armor);
        for( i=0; i<sizeof(types); i++ ) {
            if( !armor[types[i]] ) continue;
            armor_ac = armor[types[i]]->query("armor_class");
            armor_ac -= armor[types[i]]->query("ac_damaged");
            armor_db = armor[types[i]]->query("defense_bonus");
            armor_db -= armor[types[i]]->query("db_damaged");
            equip_level = armor[types[i]]->query("equip_level");
            switch( equip_level ) {
                case 0 : break;
                case 1 : armor_ac /= 2; armor_db /= 2; break;
                case 2 : armor_ac /= 4; armor_db /= 4; break;
                default : break;
            }
            ac += armor_ac;
            db += armor_db;
        }
    }

    // max db and extra_db limit.
    if( userp(this_object()) ) {
        max_db = this_object()->query_stat("int") +
                 this_object()->query_stat("pie");
        max_extra_db = max_db / 2;
        if( db > max_db ) db = max_db;
        if( extra_db > max_extra_db ) extra_db = max_extra_db;
    }

    ac += extra_ac;
    db += extra_db;
    set("armor_class", ac);
    set("defense_bonus", db);
    return ac;
}

// This function updates the object's bare-handed weapon_classes.
void calc_weapon_class()
{
    int my_str, wsk1, wsk2, twsk;
    int wc1, wc2, min_dam1, min_dam2, max_dam1, max_dam2;
    object weap1, weap2;

    weap1 = query("weapon1");
    weap2 = query("weapon2");
    my_str = this_object()->query_stat("strength");

    if( !weap1 && !weap2 ) {
        wc1 = my_str / 4 + 3;
        min_dam1 = 1;
        max_dam1 = my_str / 6 + 3;
        wsk1 = this_object()->query_skill("unarmed");
    } else {
        if( weap1 ) {
            wc1 = (int)weap1->query("weapon_class");
            wc1 -= (int)weap1->query("wc_damaged");
            min_dam1 = (int)weap1->query("min_damage");
            max_dam1 = (int)weap1->query("max_damage");
            wsk1 = this_object()->query_skill(weap1->query("type"));
        }
        if( weap2 ) {
            wc2 = (int)weap2->query("weapon_class");
            wc2 -= (int)weap2->query("wc_damaged");
            min_dam2 = (int)weap2->query("min_damage");
            max_dam2 = (int)weap2->query("max_damage");
            wsk2 = this_object()->query_skill(weap2->query("type"));
        }
    }

    wc1 += wc1 * wsk1 / 200;
    wc2 += wc2 * wsk2 / 400;

    wc1 += (int)query("natural_weapon_class1");
    wc2 += (int)query("natural_weapon_class2");
        wc1 += (int)query_temp("extra_wc");

    min_dam1 += (int)query("natural_min_damage1");
    min_dam2 += (int)query("natural_min_damage2");
    max_dam1 += (int)query("natural_max_damage1");
    max_dam2 += (int)query("natural_max_damage2");

    // Make penalty if using two weapons.
    if( weap1 && weap2 ) {
        twsk = (int)this_object()->query_skill("two-weapon");
        wc1 = wc1 * (twsk+100) / 200;
        wc2 = wc2 * (twsk+100) / 200;
        min_dam1 = min_dam1 * (twsk+100) / 200;
        min_dam2 = min_dam2 * (twsk+100) / 200;
        max_dam1 = max_dam1 * (twsk+100) / 200;
        max_dam2 = max_dam2 * (twsk+100) / 200;
    }

    if( userp(this_object()) ) {
        if( wc1 > 75 ) wc1 = 75;
        if( wc2 > 75 ) wc2 = 75;
        if( min_dam1 > 30 ) min_dam1 = 30;
        if( min_dam2 > 30 ) min_dam2 = 30;
        if( max_dam1 > 60 ) max_dam1 = 60;
        if( max_dam2 > 60 ) max_dam2 = 60;
    }
    set( "weapon_class1", wc1 );
    set( "weapon_class2", wc2 );
    set( "min_damage1", min_dam1 );
    set( "max_damage1", max_dam1 );
    set( "min_damage2", min_dam2 );
    set( "max_damage2", max_dam2 );
}

// This function is used to prevent a player from attacking for a time.
// Called by the wield command, the various spells, other places. Anything
// a players does that should interfere with his combat should call this.
void block_attack(int t)
{
    int i;

    // If we're not in combat, then don't bother.
    if( !any_attack ) return;
//	#ifdef BLOCK_ATTACK
    add("stop_attack", t/2);
//	#endif
}

// This is called in the heart_beat to decrease the blocking time.
void unblock_attack()
{
    int i;

    i = query("stop_attack")-1;
    if( i > -1 ) set("stop_attack", i);
    else set_temp("msg_stop_attack", 0);
}

// This function is used to initialize various values.
void init_attack()
{
    attackers = ({});
}

// This function returns the object we want to attack.
object query_attacker()
{
    int number;

    if( !attackers || (number=sizeof(attackers)) < 1 ) return 0;
    number = random(number);
//	write(number);
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

    if( query("linkdead") || victim==this_object() ) return 0;

    if( !attackers ) init_attack();
    if( member_array(victim, attackers)>=0 ) return 0;

    // Players cannot invis while fighting....
    this_object()->set_temp("hidding",0);
    if( !wizardp(this_object()) && this_object()->query("player_invisible") ) {
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
    if( query("npc") )
        victim = query_attacker();
    else if( attackers ) victim = attackers[0];
    if( !victim ) return;

/*
// This part of code seems obsolete, contact me if you want add it back.
// By Annihilator (12/6/94)

    // Is the target being protected? If so, find the alternate target.
    prot = victim->query("protector");
    if( objectp(prot) && prot != this_object() &&
        ((int)prot->query_level()>5) && present(prot, environment(victim)) )
        victim = prot;
*/
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
    // If we are using attack_skill, do it.
    if( func = (string)query("attack_skill") ) {
      if( now_attack_skill_type = (int)ATTACK_SKILL(func)->can_use(this_object(), victim, weapon) ) {
        if( !query("npc") ) {
        hit_chance += (int)ATTACK_SKILL(func)->hit_modify( hit_chance, this_object(), victim, weapon, now_attack_skill_type );
        pene_chance += (int)ATTACK_SKILL(func)->penetrate_modify( pene_chance, this_object(), victim, weapon, now_attack_skill_type );
        damage += (int)ATTACK_SKILL(func)->damage_modify( damage, this_object(), victim, weapon, now_attack_skill_type );
        }
      }
    }
    else this_object()->set_temp("last_attack_skill",0);

    if( victim->query_temp("block_defense") ) {
        victim->set_temp( "defense_done", 1 );
        hit_chance = 100;
    } else {
        // If opponent is using defense_skill, do it.
        if( func = (string)victim->query("defense_skill") ) {
            if( (int)DEFENSE_SKILL(func)->can_use( victim, this_object(), weapon) ) {
                if ( !victim->query("npc") ) {
                hit_chance -= (int)DEFENSE_SKILL(func)->hit_modify( hit_chance, victim, this_object(), weapon );
                pene_chance -= (int)DEFENSE_SKILL(func)->penetrate_modify( pene_chance, victim, this_object(), weapon );
                damage -= (int)DEFENSE_SKILL(func)->damage_modify( damage, victim, this_object(), weapon );
                }
            }
        }

        // The hit chance is constrained to be between
        // 5 and 95 percent. But penetrate chance is not constrained.
         if( hit_chance<5 ) hit_chance = 5;
        if( hit_chance>95 ) hit_chance = 95;
        if( pene_chance<5 ) pene_chance = 5;
    }

    // If hit and penetrate, minimum damage is 1
    if( damage < 1 ) damage = 1;

    // Check if the victim can perform a defense reaction like parry, block ...
    if( !victim->query_temp("defense_done") ) {
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
                victim->set_temp( "defense_done", 1 );
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
                victim->set_temp( "defense_done", 1 );
            }
        }

        // Chech if victim can dodge our attack.
        if( damage > 0 ) {
            if( !victim->query("npc") )
                n = (int)victim->query("load") - 400;
            else
                n = (int)victim->query("load") - 2000;
                if( n < 0 ) n = 0;
                if( random( dodge_skill/2 + hit_chance + opp_kar - n/3 ) > hit_chance ) {
                    damage = -4;
                    victim->set_temp( "defense_done", 1 );
                }
        }
    }

    // Do we hit?
    if( damage > 0 && random(100)<hit_chance ) {
        // Do we penetrate ?
        if( random(100)<pene_chance ) {
            // Hit and penetrate, give the damage and grant some exp.
            //write(damage);
            if( victim ) victim->receive_damage( damage );
            this_object()->gain_experience( damage );
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
            if( query("force_points") &&
                ( query("npc") || query_temp("enable_inner_force") ) )
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


    // We have finished the attack, enable our defense.
    set_temp( "defense_done", 0 );

    // If we are attacking with second hand/weapon, we have done enough.
    if( second_attack ) return;

    // If we are wielding two weapons, make another attack now.
    if( query("weapon_class2") && query_attackers() )
        execute_attack(1);

    // Do we lucky enough to take chance and make an extra attack ?
    if( victim && old_damage > 0 && damage > 0
        && (int)victim->query("hit_points") > -1
        && random( my_kar + opp_kar + 40 ) < my_kar ) {

        // Do we hit ?
        if(random(100)<hit_chance) {
            // Do we penetrate ?
            if( random(100) < pene_chance ) {
                victim->receive_damage( old_damage );
                gain_experience( old_damage );
            } else old_damage = 0;
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
//string dd;
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
    //add by ca
//	dd="any_attack="+ any_attack +"\n";
//	write(dd);
    //end of add
    return any_attack;
}

// Continue_attack is called from heart_beat in monster.c and user.c.
// here is where we can try to see if we're dead or in combat.
void continue_attack()
{
    string msg ;
    // Check if this object has just died. if so, do the death stuff.
    if( query("hit_points") < 1 && !query("ghost") ) {
//		write("die test1\n");
        die();
        return;
    }

    // If there's no one to attack, then we are finished.
    if( any_attack == 0 ) return;
    // Call the clean_up_attackers function to see who's left. If it returns
    // 0, then there's no one left.
    if( clean_up_attackers() == 0 ) {//write("combat test5!\n");
        write("ս��������.\n"); /* No attackers in the room */
        any_attack = 0;
        return;
    }

    // Check to see if the monster is doing something that prevents him from
    // making an attack.
    if( query("stop_attack") > 0 ) {
                if( (msg = query_temp("msg_stop_attack")) )
                        write( msg );
                else write (
                        "( �㻹û�������һ��������ʧȥһ�ι������� )\n");
        return;
    }

    // Check to see if we're under wimpy, and if so, run away.
    if( query("hit_points") < query("wimpy") ) {
        run_away();
//		return;
    }
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

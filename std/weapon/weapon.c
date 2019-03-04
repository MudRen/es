//#pragma save_binary

// Inheritable weapon object. For now.
// Mobydick@TMI-2, 9-11-92

#include <move.h>
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

string *vb, *c_vb;
object wielded_by;

// these 2 functions will run calc_weapon_class automaticly.
// So if you call them, you wouldn't need run it again.
void unwield(int silent);
void wield(int silent);

void setup_weapon( string type, int wc, int min_dam, int max_dam )
{
	ob_data["type"] = type;
	ob_data["weapon_class"] = wc;
	ob_data["min_damage"] = min_dam;
	ob_data["max_damage"] = max_dam;
}

int move(mixed dest)
{
	object fellow;

	fellow = environment(this_object());
	if( fellow && query("wielded") )
		unwield(0);
	return ::move(dest);
}

int remove()
{
	object fellow;

	fellow = environment(this_object());
	if( fellow )
		if( (object)fellow->query("weapon1")==this_object() ||
			(object)fellow->query("weapon2")==this_object() )
			unwield(0);
	return ::remove();
}

void wield(int silent)
{
	object fellow;
	mapping extra_stats, extra_skills;
	mixed stats, skills;
	string wield_func;
	int i;

	if( query("wielded") ) return;
	fellow = environment();
	if( !fellow || !living(fellow) ) return;

	// add stop wield function, by Kyoko.
	if( userp(fellow) && this_object()->stop_wield(fellow) ) return;

	// apply extra effects if exists.
	if( extra_stats = (mapping)query("extra_stats") ) {
		stats = keys( extra_stats );
		for( i=0; i<sizeof(stats); i++ )
			fellow->modify_stat( stats[i], extra_stats[stats[i]] );
    }
	if( extra_skills = (mapping)query("extra_skills") ) {
		skills = keys( extra_skills );
		for( i=0; i<sizeof(skills); i++ )
			fellow->modify_skill( skills[i], extra_skills[skills[i]] );
	}
	
	// run if wield_func exists.
	wield_func = query("wield_func");
    if( wield_func ) call_other(this_object(), wield_func);
    
	set( "wielded", 1 );
	fellow->calc_weapon_class();
}

void unwield(int silent)
{
	object fellow, firstwep, secondwep;
	string unwield_func, *stats, *skills;
	int i;
	mapping extra_stats, extra_skills;

	fellow = environment(this_object());
	if( fellow ) {
		firstwep = fellow->query("weapon1");
		secondwep = fellow->query("weapon2");
		if( !silent ) {
			tell_object( fellow, 
				sprintf("�㽫���е�%s���¡�\n",query("short"))
			);
			if( environment(fellow) )
				tell_room( environment(fellow), 
					sprintf("%s�����е�%s���¡�\n" ,
						fellow->query("c_name"),query("short") ),
					fellow
				);
		}
		if( firstwep==this_object() ) {
			if( secondwep ) {
				fellow->set( "weapon1", secondwep);
				fellow->set( "weapon2", 0);
			} else fellow->set( "weapon1", 0);
		} else fellow->set("weapon2",0);
		
		// restore extra effects.
		if( extra_stats = (mapping)this_object()->query("extra_stats") ) {
			stats = keys( extra_stats );
			for( i=0; i<sizeof(stats); i++ )
				fellow->modify_stat( stats[i], -extra_stats[stats[i]] );
		}
		if( extra_skills = (mapping)this_object()->query("extra_skills") ) {
			skills = keys( extra_skills );
			for( i=0; i<sizeof(skills); i++ )
				fellow->modify_skill( skills[i], -extra_skills[skills[i]] );
		}
		
		// do unwield function with armors.
	    unwield_func = query("unwield_func");
		if( unwield_func ) call_other(this_object(), unwield_func);
		set("wielded",0);
		fellow->calc_weapon_class();
	}
}

void set_verbs(string *verbs)
{
	c_vb = verbs;
}

void set_c_verbs(string *verbs)
{
	c_vb = verbs;
}

string get_verb()
{
	int i;

	if( !c_vb || !pointerp(c_vb) || !(i=sizeof(c_vb)) ) return 0;
	else return c_vb[random(i)];
}

string get_c_verb()
{
	int i;

	if( !c_vb || !pointerp(c_vb) || !(i=sizeof(c_vb)) ) return 0;
	else return c_vb[random(i)];
}

// Lilia@Eastern.Stories
//		1996/6/5

int poisoned_effect(object victim, int damage)
{
    // pdata: { condition_type, time, duration, harm, hit_rate }
    string type;
    int time, duration, harm, hit_rate;

    type = query("poisoned/type");
    time = query("poisoned/time");
    duration = query("poisoned/duration");
    harm = query("poisoned/harm");
    hit_rate = query("poisoned/hit_rate");

    if (random(100) < hit_rate)
    {
	(CONDITION_PREFIX + type)->apply_effect(victim, duration, harm);
	time = time - 1;
	set("poisoned/time", time);
	if (time == 0) delete("poisoned");
    }

    return damage;
}
    
int weapon_hit( object victim, int damage )
{
	string hit_func;

// Lilia@Eastern.Stories

        if (query("poisoned/type"))
                poisoned_effect(victim, damage);

	if( hit_func = (string)query("hit_func") )
		return (int)call_other( this_object(), hit_func, victim, damage );
	else
		return 0;
}

int wand_hit( object victim, int damage )
{
	object holder;
	int skill, charge, dam, my_int;
	string dam_type, msg, c_msg;

	if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if( !this_object()->query("power_on") ) return 0;
	skill = (int)holder->query_skill( "wand" );
	my_int = (int)holder->query_stat("int");
	charge = (int)query( "charge_left" );
	if( charge<1 || random(skill + my_int*3) < (int)query("weapon_class") )
		return 0;
	if (holder->query("user"))  set( "charge_left", charge-1 );
	if( !(dam = (int)query("special_damage")) ) return 0;
	if( !(dam_type = (string)query("special_damage_type")) )
		return dam;
	else {
		msg = (string)query("special_c_msg");
		victim->receive_special_damage( dam_type, dam );
		victim->set("last_attacker", holder );
		if( !c_msg ) c_msg = msg;
		if( !msg ) return 0;
		tell_object( holder, 
			sprintf("���%s%s\n",query("c_name"),msg));
		tell_room( environment(holder), 
			sprintf("%s��%s%s\n",
				holder->query("c_name") ,query("c_name"),msg),
			holder );
		return dam;
	}
}

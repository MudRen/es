//#pragma save_binary

// Inheritable armor object. For now.
// Mobydick@TMI-2, 9-11-92
// Updated by Kyoko@EasternStory, 8-22-94

#include <move.h>
#include <mudlib.h>
#include <armors.h>
#include <guilds.h>

inherit OBJECT;

// This function will run calc_armro_class automaticly.
void unequip(int silent);
// This won't bcz often equip many armors a time, for system speed.
// So after call this, you MUST run calc_armor_func!!
void equip(int silent);

string unequip_c_verb(string type);

// Armor has its own move function which forces the player to unequip the
// armor if he drops it, gives it away, or otherwise moves it.
int move( mixed dest )
{
	object fellow;

	fellow = environment(this_object());
	if( fellow && query("equipped") )
		unequip(0);
	return ::move(dest);
}

// Similarly, armor has its own remove function, to force the player to
// unequip the armor if it is dested or in some other way destructed.
int remove()
{
	object fellow;

	fellow = environment(this_object());
	if( fellow && query("equipped") )
		unequip(0);
	return ::remove();
}

string unequip_c_verb(string type)
{
	string verb;
	
	switch( type ) {
		case "head":
		case "arms":
		case "hands": verb = "����"; break;
		case "misc":
		case "finger": verb = "ȡ��"; break;
		case "body":
		case "legs":
		case "tail":
		case "cloak":
		case "feet": verb = "�ѵ�"; break;
		case "shield": verb = "����"; break;
		case "globe": verb = "����"; break;
		case "saddle": verb = "����"; break;
		case "kernel": verb = "�³�"; break;
		default: verb = "װ��"; break;
	}
	return verb;
}

// The basic equip procedure. Several commands can call this.
// Equip the object and alter the player's armor class.
void equip(int silent)
{
	mapping extra_stats, extra_skills, special_defense;
	object fellow;
	string *stats, *skills, *defenses, equip_func, material, aclass;
	int j, level;

	fellow = environment();
	if( !living(fellow) ) return;
	if( query("equipped") ) return;			

	// check if any he can't wear this armor.	
	if( userp(fellow) && this_object()->stop_equip(fellow) ) return;

	// check equip level depend on player's guild.
	set("equip_level", 0);
	if( userp(fellow) && !wizardp(fellow) ) {
		aclass = (string)fellow->query("class");
		material = (string)query("material");
		if( material != aclass )
			if( member_array(aclass, CLASS_NAMES) == -1 )
				set("equip_level", 2);
			else {
				level = (int)GUILD_MASTER(aclass)->equip_level(this_object());
				if( level < 0 || level > 2 ) level = 2;
				set("equip_level", level);
			}
	}

	// caculate extra stats, skills and special_defenses.
	if( !query("equip_level") &&
		extra_stats = (mapping)query("extra_stats") ) {
	    stats = keys( extra_stats );
	   	for( j=0; j<sizeof(stats); j++ )
			fellow->modify_stat( stats[j], extra_stats[stats[j]] );
    }
	if( !query("equip_level") &&
		extra_skills = (mapping)query("extra_skills") ) {
	    skills = keys( extra_skills );
	  	for( j=0; j<sizeof(skills); j++ )
	  		fellow->modify_skill( skills[j], extra_skills[skills[j]] );
    }
    if( (query("equip_level") < 2) &&
      	special_defense = (mapping)query("special_defense") ) {
	    defenses = keys( special_defense );
		for( j=0; j<sizeof(defenses); j++ )
			fellow->apply_special_defense( defenses[j], special_defense[defenses[j]] );
	}
	
	fellow->set("armor/"+query("type"), this_object());
	set("equipped",1);
	// run some special equip function, if is defined with armor.
	equip_func = query("equip_func");
	if( equip_func ) 
		call_other(this_object(), equip_func);	

	return;
}

// The basic unequip procedure. Several commands can call this, which is why
// it is in the armor instead of in a command daemon. Unequip the object and
// alter the player's armor class.
void unequip(int silent)
{
	object fellow;
	string type, unequip_func, verb, *stats, *skills, *defenses, *unequip_msg;
	mapping armor, extra_stats, extra_skills, special_defense;
	int aclass, j;

	fellow = environment(this_object());
	if( !nullp(fellow) ) {
		type = query("type");
		verb = unequip_c_verb(type);
		if( fellow && !silent ) {
			if( query("unequip_msg") )
				if( sizeof(unequip_msg) == 1 )
					tell_object(fellow, unequip_msg );
				else
					tell_object(fellow, can_read_chinese(fellow)?
						unequip_msg[1] : unequip_msg[0] );
			else
				tell_object(fellow, 
					sprintf("��%sװ���е�%s��\n",verb,query("short")));
			if( environment(fellow) )
				tell_room( environment(fellow), 
					sprintf("%s%sװ���е�%s��\n",fellow->query("c_name"),verb,query("short")),
					fellow
				);
		}
		
		// restore armor's extra effects.
		if( !query("equip_level") &&
			extra_stats = (mapping)query("extra_stats") ) {
	    	stats = keys( extra_stats );
	    	for( j=0; j<sizeof(stats); j++ )
		    	fellow->modify_stat( stats[j], -extra_stats[stats[j]] );
        }
	    if( !query("equip_level") &&
	    	extra_skills = (mapping)query("extra_skills") ) {
	    	skills = keys( extra_skills );
	    	for( j=0; j<sizeof(skills); j++ )
		    	fellow->modify_skill( skills[j], -extra_skills[skills[j]] );
        }
        if( (query("equip_level") < 2) &&
        	special_defense = (mapping)query("special_defense") ) {
	    	defenses = keys( special_defense );
	    	for( j=0; j<sizeof(defenses); j++ )
		    	fellow->apply_special_defense( defenses[j], -special_defense[defenses[j]] );
	    }
	    
	    // do unequip function with armors.
	    unequip_func = query("unequip_func");
		if( unequip_func ) call_other(this_object(), unequip_func);
		
		delete("equip_level");
		set("equipped", 0);
		fellow->delete("armor/"+type,armor);
		fellow->calc_armor_class();
		return;
	}
}

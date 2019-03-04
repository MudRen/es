// moorth.c
// This object is inherited by all moorth fellows
#include <mudlib.h>

inherit MONSTER;

void kill_reward(object killer)
{
	int war_score;

//	if( (string)query("class")=="knight" ) {
		war_score = (int)query("war_value");
		killer->add("war_score", war_score );
		tell_object( killer, 
			"��õ� " + war_score + " ��ս��\��\n");
//	}
	::kill_reward(killer);
}

void heal_moorth(int heal)
{
	receive_healing( heal );
}

int stop_attack()
{
	object *people;

	people = all_inventory(environment());
	people -= ({ this_object() });
	if( sizeof(people) ) people->help_me_moorth( this_object(), this_player() );
	return 0;
}

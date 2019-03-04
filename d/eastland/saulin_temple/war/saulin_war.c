
#include <mudlib.h>

inherit MONSTER;

void kill_reward(object killer)
{
        int war_score;

//      if( (string)query("class")=="monk" ) {
                war_score = (int)query("monk_value");
                killer->add("monk_score", war_score );
                tell_object( killer, 
                        "�㾡���������£��õ��� " + war_score + " �㹦\�͡�\n");
//      }
        ::kill_reward(killer);
}

void heal_attacker(int heal)
{
        receive_healing( heal );
}

int stop_attack()
{
        object *people;

        people = all_inventory(environment());
        people -= ({ this_object() });
        if( sizeof(people) ) people->help_me_attacker( this_object(), this_player() );
        return 0;
}

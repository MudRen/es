// w_island.c
// This object is inherited by all island war_fellows
// Modify from moorth.c
#include <mudlib.h>

inherit MONSTER;

void kill_reward(object killer)
{
	int war_score;

		war_score = (int)query("justice");
		killer->add("justice", war_score );
		tell_object( killer, 
			"�㱳�϶��� " + war_score + " ��Ѫ�ۡ�\n");
	::kill_reward(killer);
}

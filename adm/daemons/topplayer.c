// topplayer.c
// This daemon scores player's experience and make a top 20 list.
// By Annihilator@Eastern.Stories (5-20-94)

#define SIZE 20

#include <daemons.h>

mapping exps;
string *top_list;

void log_player(object player)
{
	int i, loc, myexp, mylevel, myage, *savedata;
	string myname;

	if( !player ) return;
	myname = (string)player->query("name");
	if( wizardp(player) ) return;
	if( PROMOTION_D->in_wiz_list(myname) ) return;

	myexp = (int)player->query_experience();
	mylevel = (int)player->query_level();
	myage = (int)player->query_age();
	savedata = ({ myexp, mylevel, myage });
	
	if( !exps ) exps = ([]);
	if( !top_list ) top_list = ({});
	
	exps[myname] = savedata;
	
	loc = member_array( myname, top_list );
	if( loc==-1 ) {
		if( sizeof(top_list) < SIZE ) {
			loc = sizeof(top_list);
			top_list += ({ myname });
		}
		else loc = SIZE;
		while( loc > 0 && (int)exps[myname][0] >= (int)exps[top_list[loc-1]][0] ) {
			if( loc < SIZE ) top_list[loc] = top_list[loc-1];
			top_list[loc-1] = myname;
			loc--;
		}
	} else {
		i = loc;
		while( i > 0 && (int)exps[myname][0] > (int)exps[top_list[i-1]][0] ) {
			if( loc < SIZE ) top_list[i] = top_list[i-1];
			top_list[i-1] = myname;
			i--;
		}
		i = loc;
		while( i < sizeof(top_list)-1 && (int)exps[myname][0] < (int)exps[top_list[i+1]][0] ) {
			if( loc < SIZE ) top_list[i] = top_list[i+1];
			top_list[i+1] = myname;
			i++;
		}
	}
}

varargs string get_list(int chinese_mode)
{
	int i,day, hour, *savedata;
	string msg;

	if( !sizeof(top_list) ) return chinese_mode?
		"������а�Ŀǰ�ǿյġ�\n": "The Top Player List is currently empty.\n";
	msg = chinese_mode?
		"������а�ǰ " + sizeof(top_list) + " ��:\n":
		"The Top " + sizeof(top_list) + " Players:\n\n";
	msg += chinese_mode?
		sprintf(" ����  �������           �ȼ�          ����ʱ��              Score\n"):
		sprintf(" Rank    Name             Level            Age                Score\n");
	for(i=0; i<sizeof(top_list); i++) {
		savedata = exps[top_list[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += chinese_mode?
			sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %20d\n",i+1, 
			top_list[i], savedata[1], day, hour, savedata[0] ):
			sprintf("  %2d. %20-s %2d %10d days %2d hours %20d\n",i+1, 
			top_list[i], savedata[1], day, hour, savedata[0] );
	}
	return msg;
}

// npc_kills.c
// This daemon scores NPC kills (players) and make a top 20 list.
// By Annihilator@Eastern.Stories (1-4-94)

#define SIZE 20

inherit "/std/save";

mapping kills;
string *top_list;

void create()
{
	seteuid( getuid() );
	kills = ([]);
	top_list = ({});
	set_persistent(1);
	save::create();
}

void add_kills(string monster)
{
	int loc;

	if( !kills ) kills = ([]);

	if( undefinedp(kills[monster]) ) kills += ([ monster: 1 ]);
	else kills[monster]++;

	loc = member_array(monster, top_list);
	if( loc==-1 )
		if( sizeof(top_list) < SIZE ) {
			top_list += ({monster});
			return;
		}
		else loc = SIZE;

	while( loc>0 && kills[monster] > kills[top_list[loc-1]] ) {
		if( loc < SIZE ) top_list[loc] = top_list[loc-1];
		top_list[loc-1] = monster;
		loc--;
	}
}

varargs string get_list(int chinese_mode)
{
	int i;
	string msg;

	if( !sizeof(top_list) ) return chinese_mode?
		"����ɱ�����а�Ŀǰ�ǿյ�.��\n": "The NPC Kills Score is empty.\n";
	msg = chinese_mode?
		"����ɱ�����а�ǰ " + sizeof(top_list) + " ��:\n":
		"The Top " + sizeof(top_list) + " NPC Killers:\n\n";
	for(i=0; i<sizeof(top_list); i++) {
		if( file_size(top_list[i]+".c")<0 ) msg += "Error loading NPC code, Notice a wizard!\n";
		else msg += sprintf( "  %2d. %40-s %5d\n",
			i+1, top_list[i]->query( chinese_mode? "short": "short"), kills[top_list[i]] );
	}
	return msg;
}

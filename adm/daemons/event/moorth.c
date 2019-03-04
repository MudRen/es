// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)

#define NODANIA "/d/noden/nodania/"
#define MOORTH_NPC "/d/moorth/monster/"

mapping attackers = ([
	NODANIA"nodania_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r2": ({
		MOORTH_NPC"officer",
		MOORTH_NPC"officer",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier"}),
	NODANIA"s_gate": ({
		MOORTH_NPC"warlord",
		MOORTH_NPC"knight",
		MOORTH_NPC"knight",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
            MOORTH_NPC"warlock",
		MOORTH_NPC"healer" })
]);

int on_war;
object *army;

void create()
{
	seteuid(getuid());
}

void announce( string msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
	usr[i]->quick_message(set_color(msg,"HIY",usr[i]));
	}
}

void start_war()
{
	if( sizeof(army)!=0 ) return;
	announce(
		"\n����������д���һ���ϸ��Ц�� ....��\n"
		"\n����������ᷢ��һ���Ц��˵��: �Ǹ���ʿ�Ѿ����ˣ�ȥ����Ů�ʱ��� ....\n"
		"\n������������ʧ�������������������\n"
	);
	call_out( "start_war1", 15 );
}

void start_war1()
{
	string *loc;
	int i, j;
	object ob, room;

	loc = keys(attackers);
	army = ({});
	call_out( "check_war", 300 );
	announce(
		"\n��Ȼ��һ���������۵�����������������������Ƽž������ ....��\n"
		"\n����������г�����\�����ǲʺ�һ��Ĺ��Σ�ʹ������г���һ�ɹ�������� ....��\n"
		"\n��˼��ʿ�ų����: Ĭ��˹�������ˣ��ʼ���ʿ�ǣ�Ϊŵ�ٵĹ��ٶ�ս�ɣ�\n\n" );
	// Clone the attackers and put them to the pre-defined rooms.
	for(i=0; i<sizeof(loc); i++ ) {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
		// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;

        tell_room( room,
            "ͻȻ�㿴��һ������ӿ��������������߳�������Ӱ��\n" );
		while( j-- ) {
			ob = new( attackers[loc[i]][j] );
			ob->move( room );
			army += ({ob});
		}
	}
	for( i=0; i<sizeof(army); i++ )
		army[i]->enable_war();
}


void check_war()
{
	// Remove those victims in the war.
	army -= ({ 0 });
	remove_call_out( "check_war" );
	if( !sizeof(army) ) {
           announce( "\n*** ս�������� ***\n\n" );
		on_war = 0;
		return;
	}
	call_out( "check_war", 300 );
}

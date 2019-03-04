// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-22-94)

#define BLUESAND "/d/noden/bluesand/"
#define PIRATE_NPC "/d/noden/bluesand/monster/"

mapping attackers = ([
	BLUESAND"jetty": ({
		PIRATE_NPC"pirate_captain",
		PIRATE_NPC"ghost_pirate",
		PIRATE_NPC"plunderer",
		PIRATE_NPC"pirate" }),
	BLUESAND"beach1": ({
		PIRATE_NPC"plunderer",
		PIRATE_NPC"pirate",
		PIRATE_NPC"pirate"}),
	BLUESAND"port_r2": ({
		PIRATE_NPC"plunderer",
		PIRATE_NPC"pirate",
		PIRATE_NPC"pirate"}),
	BLUESAND"street1": ({
		PIRATE_NPC"plunderer",
		PIRATE_NPC"pirate",
		PIRATE_NPC"pirate"})
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
		tell_object( usr[i], set_color(msg, "HIR", usr[i]) );
	}
}

void start_war()
{
	string *loc;
	int i, j;
	object ob, room;

//	if( on_war ) return;
	loc = keys(attackers);
	army = ({});
	on_war = 1;
//	call_out( "check_war", 300 );
	announce(
		"��Ȼ���㿴�������ը��һ�ź�ɫ���̻�����ʲ���ź� ....\n\n"
		"��˹���������: �ܷ��������ˣ���ҳ��һ����ɳ�۴��һƱ����ѽ�� .....\n\n" );
	// Clone the attackers and put them to the pre-defined rooms.
	for(i=0; i<sizeof(loc); i++ ) {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
		// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;

            tell_room( room,
                    "�㿴��һȺ����ˮ�ִӺ������ϰ�����\n" );
		while( j-- ) {
			ob = new( attackers[loc[i]][j] );
			ob->move( room );
			army += ({ob});
		}
	}
	for( i=0; i<sizeof(army); i++ )
		army[i]->enable_war();
}

/*
void check_war()
{
	// Remove those victims in the war.
	army -= ({});
	if( !sizeof(army) ) {
		on_war = 0;
	} 
	else
	call_out( "check_war", 300 );
}
*/
// saulin.c
// This daemon controls the wars of saulin in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)
// Modify by Ruby for SauLin Temple's war at 4-24-94
// Update by Ruby at 10-22-94
#include "/d/eastland/saulin_temple/saulin_temple.h"
#define MONSTE "/d/eastland/saulin_temple/war/"

mapping attackers = ([
	SAULIN"river_side1": ({
		MONSTE"screamer",
		MONSTE"screamer",
		MONSTE"shadow",
		MONSTE"believer",}),
	SAULIN"river_side2": ({
                MONSTE"believer",
                MONSTE"believer",
                MONSTE"shadow",
                MONSTE"ice_zombie",}),
	SAULIN"river_side3": ({
                MONSTE"ice_zombie",
                MONSTE"believer",
                MONSTE"shadow",
                MONSTE"believer",}),
	SAULIN"river_side4": ({
                MONSTE"bishop",
                MONSTE"ice_zombie",
                MONSTE"believer",
                MONSTE"believer",}),
	SAULIN"stone_path2": ({
                MONSTE"master_ninja",
                MONSTE"shadow",
                MONSTE"shadow",
                MONSTE"shadow",}),
	SAULIN"book_temple1": ({
                MONSTE"ice_zombie",
                MONSTE"ice_zombie",
                MONSTE"screamer",
                MONSTE"screamer",}),
]);

int on_war;
object *army;

void create()
{
	seteuid(getuid());
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i])) continue;
		tell_object( usr[i], c_msg);
	}
}

void start_war()
{
   if( sizeof(army)!=0 ) return;
	announce(
@MESSAGE
������һ����Ц��������ǧ�ﴫ���е�����ֻ������ͺ¿������ !! 

��ҿ�û�������ȥ��ʶ��ʶ !!

MESSAGE
	);
	call_out( "start_war1", 10 );
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
@MSG2
ͻȻ��һ����ɫ�����̻������ХȽȽ���Ͽ��оþò�ɢ��

�����µķ���ͻȻ�ӹļ�������֪������������ô����ֲؾ������ !! 
���ֵ��Ӵ˿̶�����ǰ���������� !!

MSG2
	);
// Clone the attackers and put them to the pre-defined rooms.
	for( i=0; i<sizeof(loc); i++) {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;
		tell_room( room, 
		  "ͻȻ������һ�󼱴ٵĽŲ���������װ�����ص��˷ɱ�����\n"
		  "��������Χס��\n"
		);
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
		announce( 
		          "\n\n*** ������һ�������������ԶԶ�������������ƺ��ָ������� ***\n\n" 
		);
		on_war = 0;
		return;
	}
	call_out("check_war", 300);
}

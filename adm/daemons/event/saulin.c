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
你听到一声长笑　有人用千里传音叫道　两只看门老秃驴归天了 !! 

大家快趁机上少林去见识见识 !!

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
突然　一朵青色莲花烟火夹著厉啸冉冉升上空中久久不散　

少林寺的方向突然钟鼓急鸣　你知道这代表有人擅闯少林藏经阁禁地 !! 
少林弟子此刻都速速前往保经护寺 !!

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
		  "突然你听到一阵急促的脚步声　几名装束奇特的人飞奔而来\n"
		  "将你团团围住　\n"
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
		          "\n\n*** 你听到一声声悠扬的钟声远远传来　少林寺似乎恢复宁静了 ***\n\n" 
		);
		on_war = 0;
		return;
	}
	call_out("check_war", 300);
}

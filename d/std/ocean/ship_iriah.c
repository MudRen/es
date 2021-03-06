#include <mudlib.h>
#define ROOM_OBJ "/d/std/ocean/room_iriah"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Bluesand", "蓝沙港", "/d/noden/bluesand/jetty", 30, 90 }),
	({ "Haiwei", "海威港", "/d/eastland/haiwei/jetty", 30, 90 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "frigate iriah", "依莉雅号帆船" );
	add( "id", ({ "frigate", "iriah" }) );
	set_short( "Frigate Iriah", "依莉雅号帆船" );
	set( "long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

string query_c_long()
{
	return
		"这是一艘叫做依莉雅号的美丽多桅帆船，你如果想要搭乘依莉雅号，可以\n"
		"用 board 指令搭船。\n"
		"依莉雅号的下一个目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s走上伊莉亚号帆船。\n",
		"%s从码头登上伊莉亚号。\n" }) );
	return 1;
}

// This function announce the ship is sailing in advance (20 seconds)
void announce()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"依莉雅号的水手大叫: 二十秒後开船！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"依莉雅号的水手大叫: 二十秒後开船！下一个目的地是" + schedule[next_loc][1] + "，要上船的旅客请赶快！\n" );
	call_out( "lets_go", 20 );
}

// This function sails the ship into the ocean.
void lets_go()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"依莉雅号的水手大叫: 开船罗！\n"
		"你感到船身一阵轻微的震动，依莉雅号离开了码头 ....\n" );
	tell_room( environment(this_object()), 
		"依莉雅号的水手大叫: 开船罗！\n"
		"依莉雅号缓缓地开出港口，航向辽阔的大海 ....\n" );
	call_out( "arrive", schedule[loc][4] );
	ROOM_OBJ->set_location( "ocean" );
	loc = next_loc;
}

// This function sails the ship into the ocean.
void arrive()
{
	object ship_room;

	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][2] );
	tell_room( ship_room, 
		"依莉雅号的水手大叫: " + schedule[loc][1] + "到罗！\n" );
	tell_room( environment(this_object()), 
		"你看到依莉雅号缓缓地开进码头 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}


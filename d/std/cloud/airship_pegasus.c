#include <mudlib.h>
#define ROOM_OBJ "/d/std/cloud/room_pegasus"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Easta", "若岚城", "/d/eastland/8,5.east", 20, 45 }),
	({ "Nodania", "诺达尼亚城", "/d/noden/6,8.noden", 20, 45 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "airship pegasus", "天马号飞船" );
	add( "id", ({ "airship", "pegasus", "ship" }) );
	set_short( "天马号飞船" );
	set( "long","@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

string query_c_long()
{
	return
		"这是一艘叫做天马号的飞船，她有三根巨大的桅杆，碧蓝色巨帆闪耀著\n"
		"一点一点的亮光，你如果想要搭乘天马号号，可以用 board 指令搭船。\n"
		"飞马号的收费是每人 250 枚银币。\n"
		"飞马号的下一个目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return notify_fail("Syntax: board <what>\n");
	if( !wizardp(this_player()) && !this_player()->debit( "silver", 250 ) ) {
		write( 
			"搭乘天马号飞船需要 250 枚银币，可是你钱不够。\n");
		return 1;
	} else {
		write( 
			"你付给船长 250 枚银币，登上天马号飞船。\n");
	}
	this_player()->move_player( ROOM_OBJ, ({
		"%s登上天马号飞船。\n",
		"%s登上天马号飞船。\n" }) );
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
		"天马号船长大叫: 二十秒後起飞！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"天马号船长大叫: 二十秒後起飞！下一个目的地是" + schedule[next_loc][1] + "，每个人只要 250 枚银币！\n" );
	call_out( "lets_go", 20 );
}

// This function flys the ship into the cloud.
void lets_go()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"天马号船长大叫: 起飞啦！\n"
		"你感到飞船慢慢飘离地面，天马号飞了起来 ....\n" );
	tell_room( environment(this_object()), 
		"天马号船长大叫: 起飞啦！\n"
		"天马号缓缓地升离地面，飞向辽阔的天空 ....\n" );
	call_out( "arrive", schedule[loc][4] );
	ROOM_OBJ->set_location( "cloud" );
	loc = next_loc;
}

// This function flys the ship into the ground.
void arrive()
{
	object ship_room;

	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][2] );
	tell_room( ship_room, 
		"你感到飞船开始慢慢下降，一阵轻微的震动後，飞马号平稳地著陆了。\n\n"
		"天马号船长大叫: " + schedule[loc][1] + "到罗！\n" );
	tell_room( environment(this_object()), 
		"你看到巨大的飞船天马号缓缓地由天而降，平稳地停在你面前的空地上 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}

#include <mudlib.h>

#define ROOM_OBJ "/d/std/ocean/room_death"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Bluesand", "��ɳ��", "/d/noden/bluesand/jetty", 30, 70 }),
	({ "Deathland", "�������", "/d/deathland/main/d1", 30, 70 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "ship of darkmerchant", "�ڰ����˺�" );
	add( "id", ({ "ship", "darkmerchant" }) );
	set_short( "�ڰ����˺�" );
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
		"����һ�ҽ����ڰ����˺ŵ��ƴ����������Ҫ��˺ڰ����˺ţ�����\n"
		"�� board ָ����\n"
		"�ڰ����˺ŵ���һ��Ŀ�ĵ���" + schedule[(loc+1)%sizeof(schedule)][1] + "��\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s���Ϻڰ����˺š�\n",
		"%s����ͷ���Ϻڰ����˺š�\n" }) );
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
		"�ڰ����˺ŵ�ˮ�ִ��: ��ʮ���Ὺ������һվ��" + schedule[next_loc][1] + "��\n" );
	tell_room( environment(this_object()), 
		"�ڰ����˺ŵ�ˮ�ִ��: ��ʮ���Ὺ������һ��Ŀ�ĵ���" + schedule[next_loc][1] + "��Ҫ�ϴ����ÿ���Ͽ죡\n");
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
		"�ڰ����˺ŵ�ˮ�ִ��: �����ޣ�\n"
		"��е�����һ����΢���𶯣��ڰ����˺��뿪����ͷ ....\n" );
	tell_room( environment(this_object()), 
		"�ڰ����˺ŵ�ˮ�ִ��: �����ޣ�\n"
		"�ڰ����˺Ż����ؿ����ۿڣ����������Ĵ� ....\n");
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
		"�ڰ����˺ŵ�ˮ�ִ��: " + schedule[loc][1] + "���ޣ�\n" );
	tell_room( environment(this_object()), 
		"�㿴���ڰ����˺Ż����ؿ�����ͷ ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}


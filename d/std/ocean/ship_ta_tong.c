#include <mudlib.h>
#define ROOM_OBJ "/d/std/ocean/room_ta_tong"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Haiwei", "������", "/d/eastland/haiwei/jetty", 30, 80 }),
   	({ "Deathland", "�������", "/d/deathland/main/d1", 30, 80 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "Ship of Ta-Tong", "��ͨ���洬" );
	add( "id", ({ "ship", "ta-tong" }) );
	set_short( "��ͨ���洬" );
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
		"����һ�ҽ�����ͨ�ŵ��Ͼ��洬���������Ҫ��˴�ͨ�ţ�����\n"
		"�� board ָ����\n"
		"��ͨ�ŵ���һ��Ŀ�ĵ���" + schedule[(loc+1)%sizeof(schedule)][1] + "��\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s���ϴ�ͨ���洬��\n",
		"%s����ͷ���ϴ�ͨ�š�\n" }) );
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
		"��ͨ�ŵĴ��ϴ���: ��Ҫ����������һվ��" + schedule[next_loc][1] + "��\n" );
	tell_room( environment(this_object()), 
		"��ͨ�ŵĴ��ϴ���: �쿪��������һ��Ŀ�ĵ���" + schedule[next_loc][1] + "��Ҫ�ϴ��Ŀ�����Ͽ죡\n" );
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
		"��ͨ�ŵĴ��ϴ���: �����ޣ�\n"
		"��е���ͨ�����ѡ���Ұ���Ĵ�ҡ��ҡ����ͨ���뿪����ͷ ....\n" );
	tell_room( environment(this_object()), 
		"��ͨ�ŵĴ��ϴ���: �����ޣ�\n"
		"��ͨ�Ż����ؿ����ۿڣ����������Ĵ� ....\n" );
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
		"��ͨ�ŵĴ��ϴ���: " + schedule[loc][1] + "���� ! �˿��ǸϿ��´��� !\n" );
	tell_room( environment(this_object()), 
		"�㿴����ͨ�Ż����ؿ�����ͷ ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}


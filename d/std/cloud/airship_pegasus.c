#include <mudlib.h>
#define ROOM_OBJ "/d/std/cloud/room_pegasus"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Easta", "��ᰳ�", "/d/eastland/8,5.east", 20, 45 }),
	({ "Nodania", "ŵ�����ǳ�", "/d/noden/6,8.noden", 20, 45 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "airship pegasus", "����ŷɴ�" );
	add( "id", ({ "airship", "pegasus", "ship" }) );
	set_short( "����ŷɴ�" );
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
		"����һ�ҽ�������ŵķɴ������������޴��Φ�ˣ�����ɫ�޷���ҫ��\n"
		"һ��һ������⣬�������Ҫ�������źţ������� board ָ����\n"
		"����ŵ��շ���ÿ�� 250 ö���ҡ�\n"
		"����ŵ���һ��Ŀ�ĵ���" + schedule[(loc+1)%sizeof(schedule)][1] + "��\n";
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
			"�������ŷɴ���Ҫ 250 ö���ң�������Ǯ������\n");
		return 1;
	} else {
		write( 
			"�㸶������ 250 ö���ң���������ŷɴ���\n");
	}
	this_player()->move_player( ROOM_OBJ, ({
		"%s��������ŷɴ���\n",
		"%s��������ŷɴ���\n" }) );
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
		"����Ŵ������: ��ʮ������ɣ���һվ��" + schedule[next_loc][1] + "��\n" );
	tell_room( environment(this_object()), 
		"����Ŵ������: ��ʮ������ɣ���һ��Ŀ�ĵ���" + schedule[next_loc][1] + "��ÿ����ֻҪ 250 ö���ң�\n" );
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
		"����Ŵ������: �������\n"
		"��е��ɴ�����Ʈ����棬����ŷ������� ....\n" );
	tell_room( environment(this_object()), 
		"����Ŵ������: �������\n"
		"����Ż�����������棬������������� ....\n" );
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
		"��е��ɴ���ʼ�����½���һ����΢�����ᣬ�����ƽ�ȵ���½�ˡ�\n\n"
		"����Ŵ������: " + schedule[loc][1] + "���ޣ�\n" );
	tell_room( environment(this_object()), 
		"�㿴���޴�ķɴ�����Ż��������������ƽ�ȵ�ͣ������ǰ�Ŀյ��� ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}

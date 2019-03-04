#include "island.h"

#define ROOM_OBJ "/d/island/7,2.island"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({  "noden", "/d/noden/6,6.noden", 60, 120 }),
	({  "eastland", "/d/eastland/18,10.east", 60, 120 })
                   });

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
//	set_name( "gate","�ݼ�֮��" );
	set("name","gate");
	add( "id", ({ "gate" }) );
	set_short( "�ݼ�֮��" );
	set_long(@LONG
���Ǵ�˵�����������Ŷݼ�֮������������ţ�������������ν�Ĵ���
������Ȼ˵���ţ��������Ҳ����ض����ʲ�����˵�ģ���ʵ����������
��������â�ĳ����ο����˵�����ڲ�ͬ��ʱ������ڲ�ͬ�ط�����
��ȥ�Ļ��ý���(enter)���Կ���
LONG
 );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

void init()
{
	add_action( "do_enter", "enter" );
}

int do_enter(string arg)
{
	if( !arg || !id(arg) ) 
	{
	write(@LONG
	
��Ҫ����ɶ����ѽ��

LONG
              );
	return 1;
	}
	else
	{
	write(@LONG
	
����ݼ�֮�ţ��㵽����һ���µĿռ䡣

LONG

            );
	this_player()->move_player( ROOM_OBJ,
		"\n"+this_player()->query("c_name")+"���˶ݼ�֮�š�\n",
	        "\n"+this_player()->query("c_name")+"�Ӷݼ�֮�Ž����ˡ�\n" );
	return 1;
	}
}

void announce()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()),"\n�ݼ�֮�ŵ����彥��ģ����\n\n" );
	call_out( "lets_go", 20 );
}

void lets_go()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()), "\n��Χ�Ŀռ�ָ�ԭ�����ݼ�֮�Ų����ˡ�\n\n" );
	call_out( "arrive", schedule[loc][3] );
	ROOM_OBJ->set_location( "virtual" );
	loc = next_loc;
}

void arrive()
{
	object gate_room;

	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][1] );
	tell_room( environment(this_object()),"\n��Χ�Ŀռ俪ʼŤ�����ݼ�֮�����γ���\n\n" );
	call_out( "announce", schedule[loc][2]-20 );
}


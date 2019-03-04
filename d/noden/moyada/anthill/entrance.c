// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ���");
	set_long( @C_LONG_DESCRIPTION
�㴦����޴�����ĳ�Ѩ�ڣ�����һ���޴�Ķ�Ѩ���㿴�������Ĺ�������
���������İ���ʳ��ⶴѨ��֪�ж����Ҳ�������(climb down)��ȥ������
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"out" : MOYADA"sand_square"
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant fighter"  : MOYADA"monster/ant_fighter",
	   "ant knight"   : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",6);
}

void init()
{
    add_action("to_climb", "climb");
}

int to_climb( string str )
{
    if( !str || str=="" )
      return notify_fail("��Ҫ���ĸ�����?\n");
    if( str != "down" )
      return notify_fail("�Ǹ�����ͨ��!\n");
    to_climb_down( this_player(), MOYADA"anthill/cellar1", 
      MOYADA"anthill/dump", 35, 20 );
    return 1;
}

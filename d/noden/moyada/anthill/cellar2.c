// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
���ڶ�Ѩ���м䣬���ϱ���һ��ƽ��Ķ�Ѩ����ֻ����������������������
�ƺ���ȷ�����Ƿ������ǵ�ͬ�࣬�㻹���Լ�����(climb down)��ȥ������
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	    "westdown"  : MOYADA"anthill/cabaret",
		"southeast" : MOYADA"anthill/kitchen",
	]) );
	set( "objects", ([
	   "ant worker"    : MOYADA"monster/ant_worker",
	   "ant fighter#1" : MOYADA"monster/ant_fighter",
	   "ant fighter#2" : MOYADA"monster/ant_fighter",
	   "ant knight"    : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",4);
}

void init()
{
    add_action("to_climb", "climb");
}

int to_climb( string str )
{
    if( !str || str=="" )
      return notify_fail("��Ҫ���ĸ�����?\n");
    if( str != "down" && str != "up" )
      return notify_fail("�Ǹ�����ͨ��!\n");
    if( str == "down" )
      to_climb_down( this_player(), MOYADA"anthill/cellar3", 
        MOYADA"anthill/dump", 35, 10 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/cellar1", 35 );
    return 1;
}

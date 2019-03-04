// translation done -Elon 03-10-94 (dumb...)
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
���ڶ�Ѩ���м䣬���ߺ��ϱ߶���ƽ��Ķ�Ѩ����ֻ����������������������
�ƺ���ȷ�����Ƿ������ǵ�ͬ�࣬�㻹���Լ�����(climb down)��ȥ������
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"north" : MOYADA"anthill/greeting_hall",
		"south" : MOYADA"anthill/rest_room",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant solider"  : MOYADA"monster/ant_solider",
	   "ant killer"   : MOYADA"monster/ant_killer",
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
      to_climb_down( this_player(), MOYADA"anthill/cellar2", 
        MOYADA"anthill/dump", 35, 15 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/entrance", 35 );
    return 1;
}

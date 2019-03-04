// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
���ڶ�Ѩ���м䣬���ϱߺ����߸���һ��ƽ��Ķ�Ѩ����ֻ��ʿ����������������
�����ƺ���ȷ�����Ƿ������ǵ�ͬ�࣬�㻹���Լ�����(climb down)��ȥ������
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"southeast" : MOYADA"anthill/check_point",
        "westup"    : MOYADA"anthill/cabaret",
	]) );
	set( "objects", ([
	   "ant knight#1" : MOYADA"monster/ant_knight",
	   "ant knight#2" : MOYADA"monster/ant_knight",
	   "ant solider"  : MOYADA"monster/ant_solider",
	   "ant killer#1" : MOYADA"monster/ant_killer",
	   "ant killer#2" : MOYADA"monster/ant_killer",
	   "ant killer#3" : MOYADA"monster/ant_killer",
	]) );
	reset();
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
      to_climb_down( this_player(), MOYADA"anthill/dump", 
        MOYADA"anthill/dump", 35, 5 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/cellar2", 35 );
    return 1;
}

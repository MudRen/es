// trans. done -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�㳡");
	set_long( @C_LONG_DESCRIPTION
���ѵ��ڵ�����������һƬ�㳡�����ߺ��ϱ߸���һ��ͨ���������
��������æµ�İ���һЩԲԲ�Ķ������������������ѡ�
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	   "west"   : MOYADA"anthill/check_point",
       "east"   : MOYADA"anthill/baby_room",
       "south"  : MOYADA"anthill/queen_room",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant guard" : MOYADA"monster/ant_guard",
	   "kaisa ant" : MOYADA"monster/kaisa_ant",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 4);
    ::reset();
}

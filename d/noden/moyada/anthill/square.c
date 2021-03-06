// trans. done -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("广场");
	set_long( @C_LONG_DESCRIPTION
很难得在地下有这麽大的一片广场，西边和南边各有一条通道，更多的
蚂蚁正在忙碌的搬运一些圆圆的东西，看起来像是蚁卵。
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

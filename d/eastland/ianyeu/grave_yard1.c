// File: /u/m/mad/room/grave_yard1.c
// Generated by Roommaker Tue May 23 17:29:09 1995

#include "mad.h"

inherit ROOM;

void create()
{
	::create();
   set_short( "墓场叉路" );
	set_long( @LONG_DESCRIPTION
当你爬上此山丘之顶时, 眼前出现的是一大片的乱葬岗。
抬头望去, 四周都是高大蓊郁的相思木, 因此即使是在日正当
中时, 阳光亦丝毫无法照射进这□。
LONG_DESCRIPTION
	);

   set( "objects", ([
           "zombie" : IANMOB"zombie2" ]) );
	set( "exits", ([ 
           "southeast" : IAN"grave_yard2", 
           "north" : IAN"grave_yard3", 
        "down" : "/d/eastland/11,14.east",
           "southwest" : IAN"grave_yard4" ]) );
	reset();
}


#include <hole.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "水底" );
	set_long(@LONG
这是一处地下水汇集的的地层，蜥蜴人日常的饮用水
就是由此处供应的。不过这里的水相当混浊，你甚至怀疑
这种水真的可以喝吗？
LONG
		);
	set( "exits",([ 
			"west" : HOLE"water02",
			"northeast" : HOLE"water04",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
}

#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short("井底" );
	set_long(
@LONG
你正处在这口井的井底。水面上的任何动静你已不得而知，你的四周全都被黑暗
和寂静笼罩，但往前看去，你仍可以隐约查觉到有一些光线从那里传来。
LONG
	);
	set( "exits", ([
             "up":OTEMP"well2",
	     "north" : OTEMP"well4",
	]) );
        reset();
}

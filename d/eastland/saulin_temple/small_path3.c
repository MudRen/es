#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("树林");
	set_long( @C_LONG_DESCRIPTION
这里原本是美好的树林，现在却被破坏的乱七八糟，树木倾倒的声音还不断
的传来，你不禁气的七窍生烟，惋惜这份天然美景。
C_LONG_DESCRIPTION
	);
    set("objects",([ "elephant" : SAULIN_MONSTER"elephant" ]) );
        set_outside("eastland");
	set( "exits", ([
		 "south" : SAULIN"small_path2",
	]) );
	reset();	
#include <replace_room.h>
}

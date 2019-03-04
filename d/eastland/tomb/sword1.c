#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下通道");
	set_long( 
@C_LONG_DESCRIPTION
这儿是一个阴暗的通道，四周极其地安静，你几乎可以听到自己的心跳和脚步声相呼应
著。由前方传来一波波的寒意，这是以往从未曾有过的感觉，你不禁犹豫起来，到底该不该
继续往前走呢??
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/square13", 
		"west" : TOMB"/sword2",  ]) );
	reset();	
#include <replace_room.h>
}


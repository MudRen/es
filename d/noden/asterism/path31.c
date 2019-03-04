// File: /d/noden/asterism/path31.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("小径");
	set_long(
		@C_LONG_DESCRIPTION
你现在正漫步在一片树林中。四周的蝉鸣鸟声使你几乎想要永远住在这人间仙境,
不再回到那纷扰的世界。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
//	set( "light", 1 );
	set( "exits", ([
	        "east" : ASTR"path3",
		]) );
        set("objects",([
                "monkey#1" : MOB"monkey" ,     
                "monkey#2" : MOB"monkey" ,     
                ]) ) ;
	reset();
#include "replace_room.h"
}

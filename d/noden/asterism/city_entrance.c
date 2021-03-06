// File: /d/noden/asterism/city_entrance.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("城门入口");
	set_long( 
		@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的入口, 高耸的城墙石壁, 精致的镶壁雕像,
每一个细节都显示出这个城的不平凡。 三根巨大的旗子飘扬在城门上头, 代表著
三族和平共处的象徵。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"ladder03",
		"east" : ASTR"city54", 
		]) );
	reset();
#include "replace_room.h"
}

// File: /d/noden/asterism/underpath.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("the count of conference room", "会议室前大厅");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
          这里是三族评议会会议室前的广场，三族平时各事其政，除有
紧急事件发生外，三族长老只有在每年"圣战纪念日"时，才会结合"永恒之钥"
打开会议室大门。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
          "north"  : ASTR"conferance_room",
           "east"   : ASTR"tower1-0",
           "south"  : ASTR"tower3-0",
           "west"   : ASTR"tower2-0",
		]) ) ;
	create_door("north","south",([
               "name" : "obsidian door",
                "c_name" : "黑曜石大门",
               "keyword" : ({"obsidian door","door",}),
               "c_desc" : "黑曜石大门",
               "status" : "locked",
               "lock" : "ASTERISM_2",
	                         ])
	            ) ;
	                         
	reset();
}

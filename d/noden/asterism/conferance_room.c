// File: /d/noden/asterism/conferance_room.c

#include "asterism.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("�������");
	set_long(
		@C_LONG
������������������Ĵ�����ң�������Ҳ������������Ľ��ء�
C_LONG
	);
  	set( "light", 1 );
	set( "exits",([
           	        "north" : ASTR"court",
                           "south" : ASTR"underpath",
		      ])  ) ;
	create_door("north","south",([
	            "name"   : "obsidian door",
               "c_name" : "����ʯ����",
               "keyword": ({ "north door", "obsidian door", "door","gate", }),
	            "c_desc" : "����ʯ����",
	            "status" : "locked",
	            "lock"   : "ASTERISM_2",
	                             ])
	            ) ;
   create_door("south","north",([
        "name"   : "obsidian door",
        "c_name" : "����ʯ����",
        "keyword": ({ "south door", "obsidian door", "door","gate", }),
        "c_desc" : "����ʯ����",
        "status" : "locked",
        "lock"   : "ASTERISM_2",
   ]) );
	reset();
}

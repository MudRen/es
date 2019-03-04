// File: /d/noden/asterism/underpath.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("the count of conference room", "������ǰ����");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
          ��������������������ǰ�Ĺ㳡������ƽʱ��������������
�����¼������⣬���峤��ֻ����ÿ��"ʥս������"ʱ���Ż���"����֮Կ"
�򿪻����Ҵ��š�
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
                "c_name" : "����ʯ����",
               "keyword" : ({"obsidian door","door",}),
               "c_desc" : "����ʯ����",
               "status" : "locked",
               "lock" : "ASTERISM_2",
	                         ])
	            ) ;
	                         
	reset();
}

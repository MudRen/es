// File: /d/noden/asterism/court.c

#include "asterism.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("������ǰ����");
	set_long(
		@C_LONG_DESCRIPTION
���������峤������������ǰ�Ĺ㳡������ƽʱ�������������н���
�¼������⣬���峤��ֻ����ÿ��"ʥս������"ʱ���Ż���"����֮Կ"
�򿪻����Ҵ��š�
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                    "south"  : ASTR"conferance_room",
		"north"  : ASTR"tower3-0",
		]) ) ;
		
	create_door("south","north",([
	            "name":"obsidian door",
                    "c_name":"����ʯ����",
	            "keyword":({"obsidian door","door",}),
	            "c_desc":"һ�����ʯ���š�"
	                     "��ע�⵽�������ŵ��м�ӷ촦�п������ΰ���",
	            "status":"locked",
	            "lock":"ASTERISM_2",
	                         ])
	            ) ;
	                         
	reset();
}

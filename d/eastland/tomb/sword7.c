#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("ʯ��");
	set_long( 
@C_LONG_DESCRIPTION
�������һ��СС��ʯ�ң���������������������С��΢����������ܿ���һ�ֻ
��һ������¶��ص���ǽ�ߡ�
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"east" : TOMB"/sword4",  ]) );
	set( "objects", ([
		"swordman" : MOB"/sword_saint" ]) );
	reset();	
#include <replace_room.h>
}


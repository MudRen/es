#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
����ԭ�������õ����֣�����ȴ���ƻ������߰��㣬��ľ�㵹������������
�Ĵ������㲻�������������̣���ϧ�����Ȼ������
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

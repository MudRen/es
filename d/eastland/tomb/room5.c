#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("������");
	set_long( 
@C_LONG_DESCRIPTION
�����һ����������������Կ���ǰ����Լ���������⡣һ����ķ��ǰ��������
�����ſ쵽�˰�.......
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/room6", 
		"south" : TOMB"/room4",  ]) );
	reset();	
#include <replace_room.h>
}


#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����ʯ��");
	set_long( 
@C_LONG_DESCRIPTION
�������һ�������ʯ�ң����ܵ�ǽ�������Ϻ�ʯש���ɵġ�һЩ���Ǽ������Ʒ����
�ذ��������ֻ�ǿ����Ѿ��ܾ�û���˶�����Щ�����ˡ�
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TOMB"/room1",  ]) );
	reset();	
#include <replace_room.h>
}


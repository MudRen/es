#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�ص�");
	set_long(
@C_LONG_DESCRIPTION
�����һ�������ĵص��������Ǿ��Եļž������������˽Ų����⣬��ֻ�����Լ�����
�����������ֻ����У���Ψһ�������¾��ǸϿ���ǰ�ߣ��뿪��������񾭽�������������
�ĵط���
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"up" : TOMB"/square9", 
		"down" : TOMB"/down2",  ]) );
	reset();
#include <replace_room.h>		
}


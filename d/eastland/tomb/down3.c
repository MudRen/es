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
		"up" : TOMB"/down2", 
		"down" : TOMB"/gate",  ]) );
	reset();	
#include <replace_room.h>
}

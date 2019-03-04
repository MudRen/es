// File: /d/noden/asterism/city_entrance.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�������");
	set_long( 
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵ����, ���ʵĳ�ǽʯ��, ���µ���ڵ���,
ÿһ��ϸ�ڶ���ʾ������ǵĲ�ƽ���� �����޴������Ʈ���ڳ�����ͷ, ������
�����ƽ���������硣
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"ladder03",
		"east" : ASTR"city54", 
		]) );
	reset();
#include "replace_room.h"
}

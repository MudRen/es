// File: /d/noden/asterism/city_garden.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ϯ����˹��԰");
	set_long( 
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵĻ�԰,�ɰ������峤ϯ����˹һ��
��ʼ������,ֱ�������⻨԰�Ĺ�ģ�Ѿ��൱�Ӵ���,�����������ĵ�
��̫��,��������Ļ��ݶ�����춺�����ֲ��.�����㽫�ص����·,����
�ϱ�����һ���޴�Ľ����� ,����ԼԼ�����ϱ��㿴��һ���ܸߵ���.��
����һ����������ķ���.�����￴��ȥ��ֻ��֪����������ֲ������ҡ�
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city31",
		"south":ASTR"city_library",
		]) );
	reset();
#include "replace_room.h"
}

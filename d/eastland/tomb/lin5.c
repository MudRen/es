#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( 
@C_LONG_DESCRIPTION
�������һƬ���� !! ʵ���޷������ڵص����������һƬ��˴�����֣����һ�����
���ïʢ���������˳Ծ���΢�����ᴵ�����������ʮ��������㿴����Щ���ӵĸ�������
һ������Ĺ�â��Χ��������������������������������ԭ���ڶ�����һ�����µ�С
�ݣ�����Ҳ\��\�������Ƕ��ҵ�Ϊ�εص��»��������һ���ط���ԭ��
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"south" : TOMB"/lin4",
		"east" : TOMB"/house1",
		"west" : TOMB"/lin6" ]) ); 
	reset();	
#include <replace_room.h>
}


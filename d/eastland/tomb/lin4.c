#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( 
@C_LONG_DESCRIPTION
�������һƬ���� !! ʵ���޷������ڵص����������һƬ��˴�����֣����һ�����
���ïʢ���������˳Ծ���΢�����ᴵ�����������ʮ��������е�������˯���㿴����
Щ���ӵĸ�������һ������Ĺ�â��Χ��������������������������������ԭ��
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"north" : TOMB"/lin5",
		"south" : TOMB"/lin3",
		"west" : TOMB"/lin1" ]) ); 
	reset();	
#include <replace_room.h>
}


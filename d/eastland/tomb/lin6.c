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
		"south" : TOMB"/lin1",
		"east" : TOMB"/lin5" ]) ); 
	set( "objects", ([
		"snake" : MOB"/snake" ]) );
	reset();	
#include <replace_room.h>
}


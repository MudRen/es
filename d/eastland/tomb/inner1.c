#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ");
	set_long( 
@C_LONG_DESCRIPTION
����춽�����˵�е���Ĺ�� !! ���ֱ�����������������ľ�������ͷ���Ͼ���һƬ
�貵��ǿգ����������ý�������ģ���һ����������һ������覵ı��������������
�ǿ����¡�������ǰ�����ľ�����С��Ķ�����½ !! ����ɽ������ľ�����޲�ά��άФ��
��������������ˮ�ڻ���������������̫�����ˣ���֪��ǰ������δ������㾰��ίʵ
���˾��塣
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/gate",
		"east"  : TOMB"/inner2",
		"west"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}


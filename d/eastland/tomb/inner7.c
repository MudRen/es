#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ");
	set_long( 
@C_LONG_DESCRIPTION
������Ǵ�˵�е���Ĺ�ˣ�����ͷ���Ͼ���һƬ�貵��ǿգ����������ý�������ģ�
��һ����������һ������覵ı���������������ǿ����¡����㶫������������С���
������½ !! ����ɽ������ľ�����޲�ά��άФ����������������ˮ�ڻ���������������̫
�����ˣ���֪��ǰ������δ������㾰��ίʵ���˾��塣��������һ�洿��ɫ��ǽ�ڣ�
�Ҳ���һ���ۼ���
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north"  : TOMB"/inner6",
		"south"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}


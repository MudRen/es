#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ");
	set_long( 
@C_LONG_DESCRIPTION
������Ǵ�˵�е���Ĺ�ˣ�����ͷ���Ͼ���һƬ�貵��ǿգ����������ý�������ģ�
��һ����������һ������覵ı���������������ǿ����¡�������������������С���
������½ !! ����ɽ������ľ�����޲�ά��άФ����������������ˮ�ڻ���������������̫
�����ˣ���֪��ǰ������δ������㾰��ίʵ���˾��塣��������һ���ɫ��ǽ��ǽ��
�ڵķ�����
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north"  : TOMB"/inner4",
		"south"  : TOMB"/inner2"  ]) );
	reset();	
#include <replace_room.h>
}


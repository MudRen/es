// File: /d/eastland/goomay/row14.c
// Generated by Roommaker Thu Nov 23 18:36:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��ʯ����");
	ob->set_long( @LONG_DESCRIPTION
�����ڹ�÷��ƽ̹����ʯ����ϣ�������ʯ����ʾ���������Ļ�����
�����������ߵ���С����ߺ��������������������ż�����۶����Ŀ�������
��һЩ��Ҫ���������������÷������糾ɳ�У���֪�����˶��������˵�
���롣�ֵ����������ȥ���Ϸ���ӭ����ջ��
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/col21", 
		"west" : "/d/eastland/goomay/row15", 
		"south" : "/d/eastland/goomay/guess_house" ]) );
	ob->reset();
}
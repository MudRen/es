// File: /d/eastland/mumar/m_kitchen.c
// Generated by Roommaker Sat Nov 25 13:55:49 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���еĻ﷿");
	ob->set_long( @LONG_DESCRIPTION
�����Ǿ��е������صĻ﷿��ԭ���ù���ǽ�ϵ����������ɢ���ڵ��ϵĸ���
���䣬����֮�⣬�����϶���һЩ��������Ŀ�Ͱ�ӡ����ܵ�ǽ�ں͵���̨��ȫ��
һЩ�С�����ץ���ĺۼ�������������ĳ��̰�Ե�Ұ�޵ļҡ�
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/mumar/m_square" ]) );
	ob->set( "objects", ([ 
		"rat" : "/d/eastland/mumar/monster/rat" ]) );
	ob->reset();
}
// File: /d/eastland/beggar/area/north5.c
// Generated by Roommaker Thu Mar 21 18:11:22 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��·");
	ob->set_long( @LONG_DESCRIPTION
������������һ����Ϊ����Ĵ�·��,Լ��������ƥ�����С���·�������Ϸ�
�����졣������·��������Ǭ����,·�Ե�ֲ���޼��ĺ�����,������������,����
�㳡��Ƭ��ͺͺ�ľ������ǲ��ɶ���Ͼ����������Ӽ����ϴ�����,��˵�Ǵ���
����ĵ�·���������, ȴ�������κ��˹������������ĺۼ�,��һ���ǳ����
ĳλ����֮�֡��ɱ���ԶԶ����ȥ,һ���Ű����ķ�����Ȼ�Ǵ������Ǿ�ס�ĵط�
������ͨ�������Ʒ���������
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/beggar/area/north3.c", 
		"west" : "/d/eastland/beggar/area/north8.c" ]) );
	ob->reset();
}
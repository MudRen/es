// File: /d/eastland/saulin_temple/back_temple.c
// Generated by Roommaker Wed Nov 22 22:57:53 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���");
	ob->set_long( @LONG_DESCRIPTION
�տ�������һ�����������й��������Ĳ����⣬�����Ǳ��޳��
����ĵ�������羵�����񳣳���һ��Ⱥ�����ڵ����Ƶģ�Ҳ��\����������
ɮ�˲��������ĵط�����������ȴ��һƬ���š��ϱ�������һ�����ȡ�
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/saulin_temple/hallway22", 
		"south" : "/d/eastland/saulin_temple/hallway12" ]) );
	ob->reset();
}
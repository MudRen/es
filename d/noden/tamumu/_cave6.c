// File: /d/noden/tamumu/cave6.c
// Generated by Roommaker Mon Dec  4 19:43:40 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��Ѩ");
	ob->set_long( @LONG_DESCRIPTION
�������һ����խ��ͨ�����������Ե�ʯ�ڸ���һ�ֲ�Ѱ����ѹ�ȸУ����
ͷ����ʱ����һ���������֨֨���������ϲ�֪��Ϊʲ��ʪ������һƬ��������
���಻֪������̦��������С�ĵ�ǰ�����⻬����
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"northwest" : "/d/noden/tamumu/cave7", 
		"south" : "/d/noden/tamumu/altar" ]) );
	ob->reset();
}
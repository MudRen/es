// File: /d/noden/forest/ruin/hidden_path4.c
// Generated by Roommaker Mon Dec  4 21:22:02 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�޾�");
	ob->set_long( @LONG_DESCRIPTION
С���ϱ���������������, ����ң�������ɽͷ, �е�ģ����Ӱ����
����ʶ���Լ�ԭ���Ѿ���������Զѽ! ��������, ȫ�����ʵ�ɽӰ, ���
С��ص�������ȫ��ɽ����Χ��, �ѹ��˼���������������·��, һЩ��
ɢ��ʯ�屻���ڵ�����, ����\С�����յ��Ѿ��ӽ��˰�?
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"north" : "/d/noden/forest/ruin/entry", 
		"south" : "/d/noden/forest/ruin/hidden_path3" ]) );
	ob->set( "objects", ([ 
		"wolf3" : "/d/noden/monster/wolf", 
		"wolf1" : "/d/noden/monster/wolf", 
		"wolf2" : "/d/noden/monster/wolf" ]) );
	ob->reset();
}
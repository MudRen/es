// File: /d/eastland/liang_shan/path8.c
// Generated by Roommaker Tue Nov 21 16:03:39 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�ּ�С��");
	ob->set_long( @LONG_DESCRIPTION
��������һ���ž����ּ�С���������мд���ɽ�����е�������Ϣ��
���¸�����Կ�����ɽ������Ӱ���������֣��˼�����֣��Ѹ��ĺ�Զ
��Զ��Ψһ�����죬����ֻ�����������ּ��Щ��΢�磬�ͽŲ�̤����Ҷ
�����ϵ����졣��! ��ϸ�����������ƺ�����һ������?
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/liang_shan/gate2", 
		"south" : "/d/eastland/liang_shan/path7" ]) );
	ob->set( "objects", ([ 
		"squirrel1" : "/d/eastland/monster/squirrel" ]) );
	ob->reset();
}
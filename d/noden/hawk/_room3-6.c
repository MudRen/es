// File: /d/noden/hawk/room3-6.c
// Generated by Roommaker Mon Sep 30 14:41:43 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����칫��");
	ob->set_long( @LONG_DESCRIPTION
������������������ס�ĵط������ǽ�߷������������ı���������
������������ʹ�õ���������;���ǿ������������ף�������߽䱸ɭ��
��Ȱ�㻹�ǲ�Ҫͼı���졣
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/noden/hawk/room3-1" ]) );
	ob->set( "objects", ([ 
		"leader" : "/d/noden/hawk/monster/adolph" ]) );
	ob->reset();
}
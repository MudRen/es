// File: /d/noden/hawk/room2-19.c
// Generated by Roommaker Mon Sep 30 14:39:18 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����ս�õ�·");
	ob->set_long( @LONG_DESCRIPTION
�뿪�������������ֿ�ʼ�е�һ�ɳ��ص�ѹ�����������˳������ˣ�����
ȴ������������Ѳ�ߵ�ʿ����
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"southwest" : "/d/noden/hawk/room2-17", 
		"northup" : "/d/noden/hawk/room2-21" ]) );
	ob->reset();
}
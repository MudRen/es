// File: /d/noden/10,10.noden.c
// Generated by Roommaker Tue Nov 21 00:21:54 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɽ��");
	ob->set_long( @LONG_DESCRIPTION
����������һ���ߴ�ɽ���ɽ���£�������һ����ʯ·����Ķ�������һ��
Ͽ�ȣ�����ĵ����Ըߣ��㷢�ֵ����ƺ���һЩ�����߹��ĺۼ���һ����������
��ɽ·ͨ�����ϱߵ�ɽ�ϡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"southwest" : "/d/noden/hawk/path1", 
		"east" : "d/noden/11,10.noden", 
		"north" : "d/noden/10,9.noden" ]) );
	ob->set( "original", "d/noden/10,10" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 10 );
	ob->set( "y_coordinate", 10 );
	ob->reset();
}
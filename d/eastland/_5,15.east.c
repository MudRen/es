// File: /d/eastland/5,15.east.c
// Generated by Roommaker Wed Nov 22 13:15:49 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��·");
	ob->set_long( @LONG_DESCRIPTION
������������һ����ʯ�̳ɵĵ�·�ϣ���·�򶫡����������졣·�ԵĲ�
���ϳ���һЩ��֪����Ұ����Ұ�ݡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/eastland/6,15.east", 
		"west" : "/d/eastland/yogor/eastgate", 
		"north" : "d/eastland/5,14.east", 
		"south" : "d/eastland/5,16.east" ]) );
	ob->set( "original", "d/eastland/5,15" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 5 );
	ob->set( "y_coordinate", 15 );
	ob->reset();
}
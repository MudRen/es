// File: /d/eastland/16,8.east.c
// Generated by Roommaker Wed Nov 22 13:10:01 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɳ̲");
	ob->set_long( @LONG_DESCRIPTION
�����������˺��ߵ�ɳ̲�ϣ�һ���޼ʵĴ���Զ���ͱ����������ӣ�ʹ
����ȴ�˷��ա�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"south" : "d/eastland/16,9.east", 
		"north" : "d/eastland/16,7.east", 
		"west" : "d/eastland/15,8.east" ]) );
	ob->set( "objects", ([ 
		"crab#1" : "/d/eastland/monster/crab", 
		"crab#2" : "/d/eastland/monster/crab" ]) );
	ob->set( "original", "d/eastland/16,8" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 16 );
	ob->set( "y_coordinate", 8 );
	ob->reset();
}
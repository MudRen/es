// File: /d/eastland/beggar/area/forest2.c
// Generated by Roommaker Fri Mar 22 01:41:52 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
��������һƬ�����͵�������,����ܰ���,��������ĺõط���
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exit_suppress", ({ 
		"west" }) );
	ob->set( "exits", ([ 
		"west" : "/d/eastland/beggar/area/forest3", 
		"south" : "/d/eastland/beggar/area/forest1" ]) );
	ob->set( "objects", ([ 
		"fly2" : "/d/eastland/beggar/monster/dragon_fly.c", 
		"fly1" : "/d/eastland/beggar/monster/dragon_fly.c" ]) );
	ob->reset();
}
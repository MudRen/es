// File: /d/eastland/beggar/area/forest3.c
// Generated by Roommaker Fri Mar 22 01:42:03 1996

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
		"south" }) );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/forest2", 
		"south" : "/d/eastland/beggar/area/forest4" ]) );
	ob->set( "objects", ([ 
		"moth1" : "/d/eastland/beggar/monster/moth.c", 
		"moth2" : "/d/eastland/beggar/monster/moth.c", 
		"moth3" : "/d/eastland/beggar/monster/moth.c" ]) );
	ob->reset();
}
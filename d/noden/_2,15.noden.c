// File: /d/noden/2,15.noden.c
// Generated by Roommaker Tue Nov 21 00:39:48 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�ݵ�");
	ob->set_long( @LONG_DESCRIPTION
����������һƬ�����͵Ĳݵ��ϣ����Ĳݵش����������õ�
��Ϣ������ֲ��ɢ���ڱ��̵Ĳݵؼ䣬��׺������ͷ׵Ĳ�֪��Ұ
����ʹ���Ŀ����ˡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/3,15.noden", 
		"west" : "d/noden/1,15.noden", 
		"north" : "d/noden/2,14.noden", 
		"south" : "d/noden/2,16.noden" ]) );
	ob->set( "original", "d/noden/2,15" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 2 );
	ob->set( "y_coordinate", 15 );
        ob->set( "objects", (["mob5":"/d/noden/recamp/npc/mob5.c"])) ;
	ob->reset();
}
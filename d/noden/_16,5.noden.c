// File: /d/noden/16,5.noden.c
// Generated by Roommaker Mon Nov 20 14:39:47 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɭ��");
	ob->set_long( @LONG_DESCRIPTION
������������һ��ɭ��֮�У���ï����ľɢ����һ�ɵ����ġ�
��ˬ���˵���Ϣ����������ȴ����ذ��������������ּ��������
�ŵ���һ����Ҷ����������վ���ĵط���
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/17,5.noden", 
		"west" : "d/noden/15,5.noden", 
		"north" : "d/noden/16,4.noden", 
		"south" : "d/noden/16,6.noden" ]) );
	ob->set( "objects", ([ 
		"crow" : "/d/noden/monster/spec_crow" ]) );
	ob->set( "original", "d/noden/16,5" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 16 );
	ob->set( "y_coordinate", 5 );
	ob->reset();
}
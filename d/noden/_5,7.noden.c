// File: /d/noden/5,7.noden.c
// Generated by Roommaker Tue Nov 21 00:43:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɭ��");
	ob->set_long( @LONG_DESCRIPTION
������������һ��ɭ��֮�У���ï����ľɢ����һ�ɵ����ġ�
��ˬ���˵���Ϣ��������������ּ�С��֨֨���������������ŵ�
��һ����Ҷ����������վ���ĵط���
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/castle_r0", 
		"south" : "d/noden/5,8.noden", 
		"north" : "d/noden/5,6.noden", 
		"west" : "d/noden/4,7.noden" ]) );
	ob->set( "original", "d/noden/5,7" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 5 );
	ob->set( "y_coordinate", 7 );
	ob->reset();
}
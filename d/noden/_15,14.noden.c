// File: /d/noden/15,14.noden.c
// Generated by Roommaker Tue Nov 21 00:30:48 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
������������һ����Ţ�������У��ںڵ�����д���������Ż
�ĳ�ζ���㲻�ò���ס���ӣ��ཬ�в�������ɫ��ֲ�Ｐ��������
��������һЩ�ߴ�ֲ��Ķ��˿������ٹ���İ׻���
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/16,14.noden", 
		"west" : "d/noden/14,14.noden", 
		"north" : "d/noden/15,13.noden", 
		"south" : "d/noden/15,15.noden" ]) );
	ob->set( "objects", ([ 
		"frog#2" : "/d/noden/monster/swamp_frog", 
		"frog#1" : "/d/noden/monster/swamp_frog" ]) );
	ob->set( "original", "d/noden/15,14" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 15 );
	ob->set( "y_coordinate", 14 );
	ob->reset();
}
// File: /d/eastland/easta/palace_se.c
// Generated by Roommaker Sat Nov 25 17:07:45 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����¥");
	ob->set_long( @LONG_DESCRIPTION
��������������᰹����Ͻǣ�����¥ǰ�Ĺ㳡��¥ǰ����ʯ��ɵ���ʮ��ֻ
�����������һ���������ǰ�ζ���ӳ�����ɫ����᰹��ߴ�Ĺ�ǽ������һ��
����ľ��󣬹㳡�ϱߺͶ��ߵĺ�ͬͨ������ֺ��ϴ�֡�
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/east_salley", 
		"north" : "/d/eastland/easta/palace_e", 
		"south" : "/d/eastland/easta/south_ealley", 
		"west" : "/d/eastland/easta/palace_s" ]) );
	ob->set( "objects", ([ 
		"vistor2" : "/d/eastland/easta/monster/vistor", 
		"visitor1" : "/d/eastland/easta/monster/vistor" ]) );
	ob->reset();
}
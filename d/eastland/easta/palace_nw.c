// File: /d/eastland/easta/palace_nw.c
// Generated by Roommaker Sun Jan 30 05:47:16 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("�ƺ�¥");
	set_long( @C_LONG_DESCRIPTION
��������������᰹������ǣ��ƺ�¥ǰ�Ĺ㳡����˵���������˳����ƺ�����
������ȫ�ô���ʯ���ɵ���¥��ʫ���٣�����ͬʱҲ����\��������ʿ������������
��һ����ʤ���ƺ�¥�ư�ɫ����Ӱ�����᷽���ɫ����᰹���ǽ���γ����˿��е�
����᰺�ѩ���澰��
C_LONG_DESCRIPTION
	);

	set_outside( "eastland" );
	set( "light", 1 );
	set( "exits", ([ 
		"west" : "/d/eastland/easta/west_nalley", 
		"north" : "/d/eastland/easta/north_walley", 
		"south" : "/d/eastland/easta/palace_w", 
		"east" : "/d/eastland/easta/palace_n" ]) );
	set( "objects", ([ 
		"vistor1" : "/d/eastland/easta/monster/vistor", 
		"vistor2" : "/d/eastland/easta/monster/vistor" ]) );
	reset();
#include <replace_room.h>
}
void init()
{
        if( this_player() ) this_player()->set_explore( "eastland#6" );
}
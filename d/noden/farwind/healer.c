//#pragma save_binary

// translation done 2-21-94 -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����ڽ�����һ����ȻС������ʮ������Ǭ����С�ݣ�һ��ľ�Ƶ�
�������ӣ���ֻľ�Ƶ����ӣ���ʾ���������������Ϊ�򵥣�����Կ�
��ǽ���Ϲ���һЩ��Ǭ�Ĳ�ҩ��ֲ��Լ�һЩ��֪���Ķ�����
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"out" : "/d/noden/farwind/w_gate" ]) );
	set( "objects", ([ 
		"healer" : "/d/noden/farwind/monster/healer" ]) );
	reset();
#include <replace_room.h>
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#4" );
}
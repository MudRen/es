#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
   set_short("С��");
	set_long( @LONG_DESCRIPTION
����С�����ϱ��������죬���ߵ�ǽ���ƺ�д��ʲ�ᶫ��(writing)����
����ϱ���һ��С��������һ������ʽ�Ľ�����������������������������
Ǯ�˵�ס�������������(knock)���������Ƿ�Ը������ι�һ�¡�
LONG_DESCRIPTION
	);

	set_outside( "bluesand" );
	set( "item_desc", ([ 
		"writing" : "������ʱ�������ţ����������¡���\n\n" ]) );
    set( "exits", ([ 
		"north" : "/d/noden/bluesand/alley1.c", 
		"south" : "/d/noden/bluesand/temple.c", 
		"east" : "/d/healer/building/healer_guild" ]) );
	create_door( "east", "west", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "����",
            "c_desc" : "һ�Ⱥ�ɫ�Ĺ��ţ�����װ�������ͭ����\n",
		"status" : "closed"
	]) );
	reset();
}

void init()
{
   add_action( "do_knock", "knock" );
}

int do_knock(string arg)
{
   if( !arg || arg != "door" )
   return notify_fail( "��Ҫ��ɶ?\n" );
   if( (string)this_object()->query("doors/east/status")=="open" )
   return notify_fail( "���ǿ�����, ֱ���߽�ȥ�ɡ�\n" );
   write( "���������������¡�\n" );
   tell_room( this_object(),
        this_player()->query("c_name")+"�������������¡�\n",
        this_player() );
   message( "tell_room",
        "���ߵ����⴫������..��..��..������������\n",
        "/d/healer/building/healer_guild", this_player() );
   return 1;
}

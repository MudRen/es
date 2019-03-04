// File: /d/noden/16,13.noden.c
// Generated by Roommaker Wed Dec 22 14:55:12 1993

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("��������");
	set_long( @LONG_DESCRIPTION
����������һ�������Ŀյ��ϣ����ߺ�������һƬï�ܵ�ɭ�֣��ϱߺͶ���
�����ںڶ��������ش���������ǰ����һ���������ķ��˺ܾõĹ���(house)
�����ӵ�ǽ���Ѿ��󲿷ֱ�̦޺(moss)��ֲ������ˣ���������бб�ص���һ��
���������ʹ�㲻���뵽Сʱ���������Ĺ����¡�
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "c_item_desc", ([ 
		"house" : @LONG_TEXT
������Ӵ�ž��Ǵ�˵�еĹ��ݰɣ�����û�йأ���Ҳ��ҽ�ȥ(enter)����
�Լ��ĵ�����
LONG_TEXT
, 
		"moss" : @LONG_TEXT
��Щ̦޺ֲ�￴������һ�顢��һ�飬�е����滹��һЩ��ɫ���Һ��ʵ��
�й����ġ�
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"south" : "d/noden/16,14.noden", 
		"north" : "d/noden/16,12.noden", 
		"west" : "d/noden/15,13.noden", 
		"east" : "d/noden/17,13.noden" ]) );
	set( "original", "d/noden/16,13" );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "x_coordinate", 16 );
	set( "y_coordinate", 13 );
	reset();
}

void init()
{
	add_action( "do_enter", "enter" );
}

int do_enter(string arg)
{
	if( !arg || arg!="house" ) return 0;
   write(
            "��С�ĵؿ�����ܵĴ��ţ�������ݡ�\n" );
    tell_room( this_object(),
            this_player()->query("c_cap_name") + "������ܴ��ţ�������ݡ�\n",
		this_player() );
	this_player()->move_player( "/d/noden/house/hall", "SNEAK" );
    tell_room( "/d/noden/house/hall",
            this_player()->query("c_cap_name") + "���������˽�����\n",
		this_player() );
	return 1;
}

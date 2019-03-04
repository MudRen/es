// File: 7,12.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("��ʯƽ̨");
	set_long( @LONG_DESCRIPTION
����ʯƽ̨��������ʮ��������ƽ̨��ʮ��ƽ������Ȼ������������
�����Ľ����ƽ����̨����û�ж����˵ģ�ֻ�н������˾���������һ��
��ս���������˱��ڴ˼��ϱ������Ǻ�׳�۵ĳ��棻��ƽ̨������Ƕ�
Ѩ����ˣ���ͷ������ģ��е����ˣ��ó���������ȥ�����ɣ���������
����һ����ʾ��(sign)��Ҳ����ÿ�һ����
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"7,11.island", 
		"down"  : "/d/island/hole/hole00"
		]) );
	set( "original", ISLAND"7,12" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 12 );
        set( "no_monster" , 1 );
        set( "item_desc",([ "sign":"���ʧȥ�����ı��ӣ������кܴ�ĸı�ร�\n" ]));
	reset();
#include <replace_room.h>
}


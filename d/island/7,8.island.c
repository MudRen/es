// File: 7,8.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�ϴ��");
	set_long( @LONG_DESCRIPTION
�����������ɵ��������ӳ�����ˣ�ӳ������λ��һ���Գ�Բ�ε�С
���ϣ���Ķ��������ϡ������������ĸ��������һ��ˮ�����ڣ�ˮԴ��
�����Եصף���Ȼ���Ǿ��ǵ�������СϪ��Դͷ�������Ҫ����Ļ�����
��ʯ�׶��ϣ�������������һƬ����أ������˵Ķ�Ѩ�����Ƕ���
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"northup" : ITOWN"town05", 
		"south" : ISLAND"7,9.island",
		]) );
	set( "original", ISLAND"7,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 8 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

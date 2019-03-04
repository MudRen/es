// File: 8,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�����");
	set_long( @LONG_DESCRIPTION
�����������ɵ��������ӳ�����ˣ�ӳ������λ��һ���Գ�Բ�ε�С
���ϣ���Ķ��������ϡ������������ĸ��������һ��ˮ�����ڣ�ˮԴ��
�����Եصף���Ȼ���Ǿ��ǵ�������СϪ��Դͷ�������Ҫ����Ļ�����
��ʯ�׶��ϣ��������������һƬ���ʵ����֣��Ƕ��Ǵ�˵��ħ�������
���ڵĵط���
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"westup"  : ITOWN"town07", 
		"east"  : ISLAND"9,7.island",
		]) );
	set( "original", ISLAND"8,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

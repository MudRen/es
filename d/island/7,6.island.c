// File: 7,6.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("�����");
	set_long( @LONG_DESCRIPTION
���Ͼ������ɵ��������ӳ�����ˣ�ӳ������λ��һ���Գ�Բ�ε�С
���ϣ���Ķ��������ϡ������������ĸ��������һ��ˮ�����ڣ�ˮԴ��
�����Եصף���Ȼ���Ǿ��ǵ�������СϪ��Դͷ�������Ҫ����Ļ�����
��ʯ�׶��ϣ�������������һƬ�һ��֣�·��̫���ԣ���С�ġ�
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"7,5.island", 
		"southup" : ITOWN"town01",
		]) );
	set( "original", ISLAND"7,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 6 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

// File: 6,7.island.c

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
��ʯ�׶��ϣ����������������������С���꣬���������ʿ����������
��
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,7.island", 
		"eastup"  : ITOWN"town03",
		]) );
	set( "original", ISLAND"6,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

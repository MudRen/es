#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("��·");
	set_long( @LONG_DESCRIPTION
������������һ����ʯ�̳ɵĵ�·�ϣ�������·��������Կ���ŵ������
���н֣�ŵ�����ǳ�λ��׸���ɽ��ɽ���£���������һֱ��ŵ���������׶�
���һ��ǣ�Ҳ����ý�ȥ��һ����·������һ������õ����ӣ�����д����
����ŷɴ��ؿ�վ����
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
		"west" : "d/noden/5,8.noden", 
		"north" : "/d/noden/nodania/nodania_r1", 
		"south" : "d/noden/6,9.noden", 
		"east" : "d/noden/7,8.noden" ]) );
	set( "no_monster", 1 );
	set( "original", "d/noden/6,8" );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 8 );
	reset();
	replace_program(ROOM);
}

void init()
{
	if( !find_object("/d/std/cloud/airship_pegasus") )
		"/d/std/cloud/airship_pegasus"->frog();
}

// File: /d/eastland/saulin_temple/farm2.c
// Generated by Roommaker Wed Nov 22 23:12:23 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��԰");
	ob->set_long( @LONG_DESCRIPTION
������һƬ�����Ĳ�԰��԰�д˿�������\��ɮ�˺ͳ����ڹ�������
��Щ��ض��������µ����������ճɵ����\�߹��������Ը������⻹��
���������̣���Ȼ�����е�����ӯ�Ŷ�����춼�������ƶ��
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"west" : "/d/eastland/saulin_temple/farm1", 
		"north" : "/d/eastland/saulin_temple/farm4" ]) );
	ob->set( "objects", ([ 
		"worker_leader" : "/d/eastland/saulin_temple/monster/worker_leader", 
		"worker" : "/d/eastland/saulin_temple/monster/worker" ]) );
	ob->reset();
}
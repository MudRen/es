// File: /d/eastland/saulin_temple/river_side3.c
// Generated by Roommaker Wed Nov 22 23:10:04 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�ӱ߲ݵ�");
	ob->set_long( @LONG_DESCRIPTION
������һƬ�ݵ��ϣ�������һƬ���֣�����ɽ�紵�ӡ����������⣬û
��һ�㳾�������������ľ���ɭ����Ϣ���������ÿһ������������������
�����ʱ�������׵�һ������ǣ�����ſ��������������ѵõ���Ȼ֮����
������һ��С�ӣ���ˮ���ѵ������ؾ���������ȥ���Ϸ����ǲؾ���ǰ�Ĺ�
����
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/saulin_temple/book_temple1", 
		"west" : "/d/eastland/saulin_temple/river_side1" ]) );
	ob->reset();
}
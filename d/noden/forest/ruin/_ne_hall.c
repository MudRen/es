// File: /d/noden/forest/ruin/ne_hall.c
// Generated by Roommaker Mon Dec  4 21:23:00 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
�������ɽ��֮�С����ﲢ���Ƿǳ��ڰ�, �ռ�Ҳ�൱�ع����Ȼ
�����Զ, ����ʯ�Ƶĵذ塢ǽ�����컨����ʱʱ�ɼ������ĵ��, ����
�������Ǹ����������������������������Ķ������䡣
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"west" : "/d/noden/forest/ruin/n_hall", 
		"south" : "/d/noden/forest/ruin/e_hall" ]) );
	ob->reset();
}
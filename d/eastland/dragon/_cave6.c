// File: /d/eastland/dragon/cave6.c
// Generated by Roommaker Sat Nov 25 14:00:30 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��Ѩ");
	ob->set_long( @LONG_DESCRIPTION
�������˶�Ѩʱ�㷢�ִ˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ������
��ʱ��һЩ��ֵ���ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�е�
��칹��һ�������ľ�ɫ�����㼸���������ںδ���
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/dragon/cave20", 
		"west" : "/d/eastland/dragon/cave21" ]) );
	ob->set( "objects", ([ 
		"fighter2" : "/d/eastland/dragon/monster/fighter", 
		"fighter1" : "/d/eastland/dragon/monster/fighter", 
		"fighter3" : "/d/eastland/dragon/monster/fighter" ]) );
	ob->reset();
}
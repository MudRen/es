// File: /d/noden/hawk/crack1.c
// Generated by Roommaker Mon Dec  4 21:08:07 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��Ѩ");
	ob->set_long( @LONG_DESCRIPTION
��������վ��һ����խ�Ķ�Ѩ�У�һ��ǡ������һ����ͨ�����ѷ������͸��
һЩ�谵�Ĺ��ߣ������Ѩ��խ�������㷢�ֶ�Ѩ�Ķ�����һ��ɹ���������ʯͻ
����ֻҪ����΢һ���͹���������Ѩ������һ��������ѷ죬���������ġ�
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"out" : "/d/noden/hawk/clearing", 
		"down" : "/d/noden/hawk/crack3", 
		"up" : "/d/noden/hawk/crack2" ]) );
	ob->set( "objects", ([ 
		"worm#1" : "/d/noden/hawk/monster/cave_worm", 
		"worm#2" : "/d/noden/hawk/monster/cave_worm" ]) );
	ob->reset();
}
// File: /d/noden/elf/elf/elf17.c
// Generated by Roommaker Mon Dec  4 21:45:05 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ľ���鹤����");
	ob->set_long( @LONG_DESCRIPTION
"����һ������ľм�͵���ķ��䣬������Ϊ��ͨ�緽�㣬����ǽ�϶��о޴�
����ش������ӵ����������һ�źܴ�Ĺ����������Ϸ�������δ��ɵ���Ʒ
�������������֧ɢ��ľ�ƿ���ɷ��Ӽ������������������ӵ����˱ض�
��һλ�о��Ĺ�����"
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/noden/elf/elf/elf7" ]) );
	ob->set( "objects", ([ 
		"icers" : "/d/noden/elf/monster/wind" ]) );
	ob->reset();
}
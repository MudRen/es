// File: /d/noden/nodania/castle_r0.c
// Generated by Roommaker Mon Dec  4 19:51:10 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�Ǳ�·��ŵ������");
	ob->set_long( @LONG_DESCRIPTION
�Ǳ�·����ŵ�����ǳǵĳ�ǽ�����������죬·�����˲�����ľ��
�����ԡ�����Ķ������Կ����Ǳ������š�
LONG_DESCRIPTION
	);

	ob->set_outside( "nodania" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/castle_r1", 
		"west" : "/d/noden/5,7.noden" ]) );
	ob->set( "no_monster", 1 );
	ob->reset();
}
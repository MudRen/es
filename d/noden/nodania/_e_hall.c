// File: /d/noden/nodania/e_hall.c
// Generated by Roommaker Mon Dec  4 20:01:42 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��������");
	ob->set_long( @LONG_DESCRIPTION
������ŵ�����������е�һ�����ȣ�����������Ե��������ĳ�����
������������ڵĴ�����
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/kitchen", 
		"west" : "/d/noden/nodania/palace_hall" ]) );
	ob->reset();
}
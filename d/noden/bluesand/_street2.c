// File: /d/noden/bluesand/street2.c
// Generated by Roommaker Mon Dec  4 22:11:56 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("街道");
	ob->set_long( @LONG_DESCRIPTION
你走在一条宽敞的街道上，左右两旁都是商人们存放货物的仓库。街道
上行人不多，但是每个人的衣饰看起来都颇为高贵。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/noden/bluesand/street1.c", 
		"south" : "/d/noden/bluesand/office" ]) );
	ob->reset();
}

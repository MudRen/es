// File: /d/noden/drow/r15.c
// Generated by Roommaker Mon Nov 27 14:18:53 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地下广场");
	ob->set_long( @LONG_DESCRIPTION
这是一个地下大广场，你已经折服於黑暗精灵族的建筑手艺，竟然
能在这由岩石所构成的地底下，建构这种大广场，这里平时是黑暗精灵
族人的主要活动场所，也是他们集会，和外来人们交换生活物资的地方
，黑暗精灵没有钱币的交易，大多以物易物。
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/drow/r16", 
		"west" : "/d/noden/drow/r14", 
		"southeast" : "/d/noden/drow/r20", 
		"northeast" : "/d/noden/drow/r11" ]) );
	ob->set( "objects", ([ 
		"guard" : "/d/noden/drow/mob/guard" ]) );
	ob->reset();
}

// File: /d/noden/recamp/camp7.c
// Generated by Roommaker Sat Nov 25 14:28:43 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地道");
	ob->set_long( @LONG_DESCRIPTION
这条神秘的地道，壁上镶嵌著耀眼明亮的珠子，照亮整个通道，壁上还绘著
一只喷火怪兽，显示在诺顿王国的西北角，相当吸引人的留意。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/noden/recamp/camp_wall", 
		"up" : "/d/noden/recamp/camp6" ]) );
	ob->set( "objects", ([ 
		"rat2" : "/d/noden/farwind/monster/fat_rat", 
		"rat1" : "/d/noden/farwind/monster/fat_rat" ]) );
	ob->reset();
}

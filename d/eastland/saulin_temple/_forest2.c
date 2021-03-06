// File: /d/eastland/saulin_temple/forest2.c
// Generated by Roommaker Wed Nov 22 23:16:40 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("林中的小径");
	ob->set_long( @LONG_DESCRIPTION
你走在一条小径上，洁净的小径显示这里经常有人走过，习习的微风
穿过林梢向你吹来，只有寂寂的四周虫鸣鸟啼和野花飘香，小径向北蜿蜒
而去。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/saulin_temple/forest3", 
		"southeast" : "/d/eastland/saulin_temple/left_path2" ]) );
	ob->set( "objects", ([ 
		"fly2" : "/d/noden/elf/monster/butterfly", 
		"fly" : "/d/noden/elf/monster/butterfly" ]) );
	ob->reset();
}

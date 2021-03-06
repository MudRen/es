// File: /d/noden/elf/elf/elf13.c
// Generated by Roommaker Mon Dec  4 21:42:14 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草原");
	ob->set_long( @LONG_DESCRIPTION
这里是一座小山丘，由此处望去四周的风景都尽在眼底，北方的精灵村
依稀可见，西方的草原一直延伸到天际，南方的小河清澈美丽。山丘的东方
好像有一个洞穴。
LONG_DESCRIPTION
	);

	ob->set_outside( "elfhamlet" );
	ob->set( "exits", ([ 
		"west" : "/d/noden/elf/elf/elf14", 
		"north" : "/d/noden/elf/elf/elf6" ]) );
	ob->set( "item_desc", ([ 
		"plain" : @LONG_TEXT
这里长满著青翠的小草，几丛灌木孤独地耸立著，虽然此处看起来
十分平静，但是据说附近常有野兽出没，故而此处是精灵们的狩
猎场。
LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"wolf" : "/d/noden/monster/wolf" ]) );
	ob->reset();
}

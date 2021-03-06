// File: /d/noden/elf/elf/elf27.c
// Generated by Roommaker Mon Dec  4 21:47:23 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草原");
	ob->set_long( @LONG_DESCRIPTION
这里是一望无际的大草原(plain)，有无数的动物生长在这里，你的眼前
有一些草丛(bushes)肃立著。此时天空一片阴暗，透露出一股肃杀的气息。
LONG_DESCRIPTION
	);

	ob->set_outside( "elf_hamlet" );
	ob->set( "exits", ([ 
		"east" : "/d/noden/elf/elf/elf25" ]) );
	ob->set( "item_desc", ([ 
		"plain" : @LONG_TEXT
这里长满著青翠的小草，几丛灌木孤独地耸立著，虽然此处看起来
十分平静，但是据说附近常有野兽出没，故而此处是精灵们的狩
猎场。
LONG_TEXT
, 
		"bushes" : "这些草丛长满荆棘你应该不能通过(pass)它\n" ]) );
	ob->set( "objects", ([ 
		"rabbit3" : "/d/noden/elf/monster/rabbit", 
		"rabbit2" : "/d/noden/elf/monster/rabbit", 
		"rabbit1" : "/d/noden/elf/monster/rabbit" ]) );
	ob->reset();
}

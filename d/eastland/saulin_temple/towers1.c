#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("塔林");
	set_long( @C_LONG_DESCRIPTION
一座座小塔将这个小丘装点的像一座丛林，这里就是少林寺著名的塔林，
相传每一位高僧坐化以後所得的舍利子都会建一座小塔来存放，看到这麽多的
塔，你可以想见少林的历史悠久与人才辈出为什麽能闻名於世。
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"grass1",
      	 "east"  : SAULIN"towers2",
		 "west"  : SAULIN"grass3",
	]) );
	set("no_monster", 1);
	reset();	
}

void init()
{
    add_action( "summon_seed", "call" );
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
 		tell_object(this_player(), 
    		"一个虚无缥缈的声音道: 你鬼叫鬼叫个什麽劲？\n" 
   		);
    else
        tell_object(this_player(), 
        "你叫了好半天，连个鬼影子也没有。\n" 
        );
   	return 1;
}

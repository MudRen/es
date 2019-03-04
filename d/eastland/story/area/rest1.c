#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「巫亭」");
	set_long( @LONG
此凉亭名为「巫亭」，乃「巫咸国」第一匠师所造，外型宏观，内亭富丽，四
周石柱雕工精细，地上种满灵花异草，芬香馥郁，真乃天下第一亭。凉亭西边有一
莲池，水清见底，鱼儿悠游自在，又乃一殊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	  "out" : SAREA"wiz3",
        ]) );
        set("objects", ([
           "poet#1" : SMOB"poet1",
           "poet#2" : SMOB"poet1",
           "poet#3" : SMOB"poet1",
        ]) ); 
	reset();
}

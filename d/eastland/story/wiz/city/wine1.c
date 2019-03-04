#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「悦来客栈」");
	set_long( @LONG
「悦来客栈」在「巫咸城」可说是最大的一间客栈，老板伙计和蔼可亲，价钱
公道，平时生意相当不错，门庭若市，座无虚席，渐渐地，名声传了开来，许多到
过「巫咸城」观光的旅客都会来这里品□佳肴美酒，顺便或多或少打听一些消息。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ee",
        ]) );
        set("objects", ([
           "captain":SWMOB"wiz_captain2"
        ]) );
	reset();
}

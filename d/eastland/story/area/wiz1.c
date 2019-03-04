#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山顶");
	set_long( @LONG
在这山顶北方的远处是层峦叠峰，好似一幕幕的绿布不住往天际延伸。西边底
下是一白茫茫的断谷，也不知道有多深，另外在断谷上有一座浮桥。抬头一望，头
上的白云只不过离顶尺许高度，宛如一条素色的被子，像要压将下来。在东北边有
条蜿延崎岖的小路，据说，可以由此通往巫咸国。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "ned"}) );
	set( "exits", ([ 
       	     "northeastdown" : SAREA"wiz2",
                       "ned" : SAREA"wiz2",
                      "west" : SAREA"bridge2"
        ]) );
	set("exit",({"west"}));
	reset();
}

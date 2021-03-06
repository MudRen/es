#include <mudlib.h>

inherit ROOM;

void create()
{
	set_short("封印之厅");
	set_long( @LONG_DESCRIPTION
你现在来到一间幽暗的大厅，在你的面前，也就是大厅的南边，一块巨大
的巨岩(rock)堵住了整个大厅的南边，你仔细一看，发现似乎这个城堡就是依
傍著这块巨岩建造的，大厅没有任何窗户，只有东西两排火把发出的微光照亮
著，你注意到大厅的正中央立著一个石碑(tablet)。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
	     "north" : "/d/noden/nodania/tower1" ]) );
	set( "item_desc", ([ 
	     "tablet" : @LONG_TEXT
石碑上只有短短的一行字:

    此地封印著通往米达尔(Mydarr)之墓穴的入口，任何人不准进入。
LONG_TEXT
, 
		"rock" : "这块巨岩看起来年代相当久远了，在火光的照耀下呈现出一种异样的血红色。\n" ]) );
	reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string str)
{
    if (!str)
	return notify_fail("你想找什麽东西?\n");
    if (str == "tablet")
    {
	tell_object(this_player(), "这个石碑似乎是某种开关 ....\n");
	return 1;
    }
    if (str == "rock")
    {
	tell_object(this_player(), "别呆了，你不可能推动这块巨岩的 ....\n");
	return 1;
    }
}

int to_push(string str)
{
    object p;
    p = this_player();

    if (!str)
	return notify_fail("你想推动什麽东西?\n");
    if (str != "tablet")
	return notify_fail("你用尽了吃奶的力气，还是推不动它。\n");
    if ((int)p->query_perm_stat("str") < 12)
	return notify_fail("太重了，你推不动 ....\n");
    else
    {
	tell_object(p, @FACE
当你推开石碑的那一刹那，巨岩忽然化成了一张狰狞的鬼脸!!

鬼脸突然伸出它长长的舌头，将你卷进它的嘴里!!

(你来到一个新的地方)

FACE
		   );
	tell_room(environment(p), sprintf("你听到一声凄厉的惨叫，回头一看%s已经不知所终了。\n", p->query("c_name")), ({p}));
     p->move_player("/d/noden/ruin/room/en0","SNEAK");
    }
    return 1;
}


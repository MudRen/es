// wenro4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("树林");
    set_long(@C_LONG
眼前所见是一片青翠的树林，林子里不时传来阵阵的歌声，伴著枝头上悦
耳的鸟啭，织成一曲动人的乐章。沐浴在这天籁之中，你顿时觉得心情舒畅不
已，也想随著这音乐放声高歌。
C_LONG
	    );
    set("exits", ([
	"west" : AREA"wenro5",
	"south" : AREA"wenro3"
	]));
    set("objects", (["bard" : MOB"bard"]));
    set("item_desc", ([
	"casablanca" : "香水百合，花中的女王，花语是伟大的爱。\n"
	]));
    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_pick", "pick");
}

int do_search(string arg)
{
    write("除了角落里长了些香水百合 (casablanca) 之外，没什麽特别的东西。\n");
    return 1;
}

int do_pick(string arg)
{
    object f;

    if (arg == "casablanca")
    {
        f = new(OBJ"casablanca");
        f->move(this_player());
        write("你摘下一朵香水百合。\n");
	return 1;
    }
    else if (arg == "flower")
	return notify_fail("你想摘什麽花?\n");
    else	
	return notify_fail("你想做什麽?\n");
}


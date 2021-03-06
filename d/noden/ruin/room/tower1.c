// tower1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．出口");
    set_long(@C_LONG
这里是魔术师塔的出口，四周堆满著各种生物的骷髅，肃杀诡秘的气氛令
人毛骨悚然。出口的大门旁立著块石碑，上面写著：「HASLAVISTA BABY!」。
C_LONG
	    );

    set("exits", (["north" : AREA"tower0"]));
    set("item_desc", ([
	"slab" : "一块残破的石碑，上面写著：「向真神祈祷」。\n"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_search(string arg)
{
    write("你找了又找，只看到地上有块小石碑 (slab)。\n");
    return 1;
}

int to_pray()
{
    write("你跪下来祈祷，祈祷些什麽呢? ....\n");
    this_player()->move(AREA"rose4");
    return 1;
}


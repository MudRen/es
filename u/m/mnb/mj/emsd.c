//emsd.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("明教");
    set_long(@C_LONG
这是一个用黄金造成的神殿，灿烂的光芒四射，在神殿中央有个祭坛
(altar),祭坛上有个和人身一样大小的庄严的神像(statue)。看来你
到了明教的神圣之地。
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
        "altar" : "一个用完整的钻石雕刻的祭坛，也许可以供奉 (gongxian) 些什麽。\n",
        "statue" : "一座刻的栩栩如生的教宗寒鸦的雕像，威严而肃穆。\n"
	]));
    reset();
}

void init()
{
    add_action("do_gongxian", "gongxian");
    add_action("do_bow", "bow");
}

int do_dedicate()
{
    object f; 
    if (f = present("torch", this_player()))
    {
        write("你把火把虔诚的供奉在祭坛上。\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
        return notify_fail("你身上没有什麽可供奉的东西,寒鸦的眼睛好象眨了眨。\n");
}

int do_bow(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
            write("你发现罗纳尔多正恶狠狠地瞪著你，小心你的屁屁。\n");
	    return 1;
	}
        else    
	{
            write("你虔诚的向神像鞠了一躬，突然间一道神奇的彩虹注入你的身体 ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
        return notify_fail("你想做什麽?\n");
}


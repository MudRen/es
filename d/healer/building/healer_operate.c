#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("手术室");
	set_long(@C_LONG_DESCRIPTION
这里是行医者公会最自豪的地方, 因为有许多行医者就在这里, 将其他玩
家从鬼门关拉了回来, 你在这里看到有最先进的手术台, 无影灯, 旁边的柜子
里整齐的放著手术刀、止血钳等手术必备工具及应用药品, 如果能在这里动手
术,相信成功的机会一定比在野外要高的多了。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );

	set( "exits", ([ 
		"north" : "/d/healer/building/healer_guild" 
		]) );
	set( "op_room",1);	
	reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_sneak", "sneak");
}

int do_search()
{
    write("墙角似乎有个狗洞，可以钻 (sneak) 过去。\n");
    return 1;
}

int do_sneak()
{
    if (this_player()->query("class") != "healer" || this_player()->query("alignment") > 0)
        return notify_fail("突然有个在你耳边回绕著：好不害臊的大胆小贼！\n");

    write("你钻过狗洞，进入行医者书房。\n");
    this_player()->move("/d/healer/building/healer_troom");
    return 1;
}

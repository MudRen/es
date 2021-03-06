
#include "hawk.h"

inherit ROOM;
int ring;
void create()
{
        ::create();
        set_short("墓穴");
	set("light",1);
        set_long( @LONG_DESCRIPTION
这显然是一个匆匆完成的墓穴，不过依稀看得出来这个墓穴的主人应该是
一个精擅武艺的人，因为四周的墙壁旁放满了各式各样的武器，有剑(sword)
，有长枪(lance)，有巨斧(axe)，还有一面体积相当庞大的盾牌。想到一代英
雄就如此草草埋在这种荒郊野地，你不禁感到人事无常。
LONG_DESCRIPTION
        );

set("c_item_desc",([
        "lance":" 这是一把青色的长枪，枪柄上还有不少图样。\n",
        "axe":" 这是一把黑色的巨斧，大概只有巨人才有办法拿的动。\n",
        "shield":"这面盾牌体积更是惊人，躲下两个人大概是不成问题。\n",
        "sword":" 这是一把生了一堆铁锈的巨剑。\n",
                ]) );
	set( "exits", ([
		"out":"/d/noden/2,5.noden" ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_search","search");
        add_action("to_pray","pray");
}

int to_search(string str)
{
        object obj;
        if ((str != "shield" && str != "盾牌") || ring == 0)
                return notify_fail( "你很努力的找来找去，不过没有啥收获。\n");
        tell_object(this_player(),
                "哇... 你找到了一枚淡绿色的戒子。\n");
	obj = new(OBJ"ring");
        obj->move(this_object());
        this_player()->set_temp("find_ring",1);
        ring = 0;
        return 1;
}

int to_pray()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_room(environment(this_player()),
                        this_player()->query("c_name") +
                        "虔诚的跪在墓前，希望亡魂能够安息。\n"
                ,this_player() );
                tell_object(this_player(),@LONG
你彷佛看到墓里飘起一股淡淡的白雾，幻化成一位英武的勇士的身影，
他对著你微笑，然後就飘向天空消失不见了。
你听到天空传来一阵雄壮而温和的声音：谢谢你，勇士，请你告诉柏妮
丝我对她永恒的眷恋。
LONG
                );
                this_player()->set_temp("smore_box",6);
       }

        return 1;
}

void reset()
{
        ::reset();
        ring = 1;
}

//room1-5.c
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("石板小径");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到这边，突然你发现到地上已经铺上了石板，走起来舒适多了，而且
慢慢的视野也越来越好。不过你还是搞不清刚刚所听到的那些奇怪的声音是
从哪里传来，可能要再往前走段路才能弄明白吧。
    小径两旁茂密的森林(forest)里，传来一阵阵森林特有的芳香，让你感
到心旷神怡。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "south" : HAWK"room1-6",
                "northwest" : HAWK"room1-4",
                     ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "skull":"@@to_skull",
                "ball":"@@to_ball"
                ]) );
        set("search_desc",([
                "forest":"@@to_search_forest",
                "skull":"@@to_search_skull"
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_move","move");
        add_action("to_touch","touch");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="northwest" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}

string to_skull()
{
        if (moves == 0) return "这里没有这样东西。\n";
        return "一棵深褐色的骷髅头, 看来年代已经相当久远了。\n";
}

string to_ball()
{
        if (moves < 2) return "这里没有这样东西。\n";
        return "一棵泛著神秘光芒的水晶球, 不断的吸引你去触摸(touch)它。\n";
}

string to_search_skull()
{
        if (moves == 0)
        {
        return "啥..? 啥..? 你要找啥...?\n";
        }
        else if (moves == 1)
        {
        moves = 2;
        return "这骷髅头下面好像有点东西,不过你可能要先移开(move)"+
               "它, 才能看得更仔细。\n";
        }
        else if (moves > 1)
        {
        return "再多找也是没有用的, 省点力气吧。\n";
        }
}

string to_search_forest()
{
        if ((moves == 0) || (moves == 1))
        {
        moves = 1;
        return "哇！你在森林的深处找到一颗骷髅头(skull)\n" ;
        }
        else
        {
        return "你再找了找, 不过没啥新发现\n";
        }
}

int to_touch(string s)
{
        if ((!s) || (s!="ball") || (moves != 3 ))
                return notify_fail("乱摸乱摸，小心下次被路上小姐告性骚扰喔\n");
        tell_object(this_player(),
                "你摸呀摸，摸呀摸，摸了半天，也没发生啥事，觉得有"+
                "一股受骗了的感觉。\n");
        this_player()->set_temp("touch_ball",1);
        return 1;
}

string to_forest()
{
        return "一片茂密的森林, 但不知怎的, 你总是觉得有一股诡异的气氛笼罩
在这片森林。你靠近森林, 隐隐约约感受到一股血腥的味道, 很多树
干上也有不少兵器杀伐所留下的痕迹, 你猜在这边一定曾有过一场大
战。\n";

}

int to_move(string str)
{
        if ((!str) || (str!="skull") || (moves == 0))
        {
                tell_object(this_player(),
                        "....乱动乱动会掉到山下去喔。\n");
                return 1;
        }

        if (moves == 1)
        {
                tell_object(this_player(),
                        "呃....你想了想，还是决定不要乱动这个骷髅头比较妥当。\n");
                return 1;
        }

        if (moves == 2)
        {
                moves = 3;
                tell_object(this_player(),
                        "你轻轻的把骷髅头移开..哇..你看到一个闪"+
                        "烁著神秘光芒的水晶球(ball)\n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "找到了一个水晶球!\n",this_player());

                return 1;
        }

        if (moves == 3)
        {
        tell_object(this_player(),"你可以不用再移了。\n");
        }
        return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}

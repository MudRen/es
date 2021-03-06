#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("御花园");
    set_long(@LONG
这是树雷王家最引以为傲的御花园，里面种满了各种难得一见的奇花异
草，如「 王家之泪」(tear_flower)，「 胜利女神 」(goddess_flower)
等等，旁边还种有一些大树(tree)，看起来和种在神社旁的及长在城外的是
同样的品种，只是树龄没那麽大；不过，这儿的美景真是令人流连忘返呀！
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway1"]) );
    set("item_desc",([
        "tear_flower":@ALONG
这是一种现在十分罕见的花卉，在古魔族帝国时代，这种花随处可见，但
自从那大陨石掉落後，这种花几乎绝迹了！这种花的花语是「悲伤，离别」
，种在这儿是为了纪念历次战争中阵亡的同胞。
ALONG
       ,"goddess_flower":@BLONG
这是魔族的王族在战争时必带的花朵，相传它可保佑王族的安全，也可
为战争带来胜利；当年这一支王族迁徙时，为了祈求平安，所以也带著它；
如今就种在这儿！                     
BLONG
        ,"tree":@CLONG
咦～～！这些树难道也是王家的守护灵吗？怎麽看起来好像是同一品种呢？
CLONG
            ]) );
    set("objects",([
        "farmer":TMOB"farmer1",
        "luoky":TMOB"luoky"]) );
    reset();
#include <replace_room.h>
}


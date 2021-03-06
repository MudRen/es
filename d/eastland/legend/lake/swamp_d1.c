#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼泽地底洞穴");
    set_long(@LONG
你来了沼泽底下一个奇怪的洞穴。没有令人掩鼻的腐朽恶臭，不见遍地的□骨，
也没有凶恶骇人的沼泽毒物怪兽；相反的，这里的空气清新的让人浑身没有一个毛孔
不畅快，四周有著闲适的宁静。北壁下一条浅浅的地下泉水蜿蜒流经，黯淡的光线下
隐隐约约可以看出东，南方各有一条通道，不知道通往什麽地方。
LONG
    );
    set("exits",([
            "eastdown":LAKE"swamp_d2",
            "south":LAKE"swamp_d3",
            "up":LAKE"swamp8",
    ]) );
    set("objects",([
          "icetoad#1":LMONSTER"icetoad",
          "icetoad#2":LMONSTER"icetoad",
          "icetoad#3":LMONSTER"icetoad",
    ]) );
    ::reset();
}


#include <mudlib.h>

inherit CONTAINER;

int left_hole,mid_hole,right_hole;

void create()
{
    ::create();
    set_name("Stone","破邪镇");
    set_short("破邪镇");
    set_long(@C_LONG
一棵巨大的天然岩块，岩块上有三个大小不同的小洞洞(hole)，
好像可以插(insert)东西耶!!
C_LONG
            );
    set("prevent_get",1);
}


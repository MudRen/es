#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山顶");
	set_long( @LONG
在这山顶北方的远处是层峦叠峰，好似一幕幕的绿布不住往天际延伸。天上白
云离头顶只不过尺许高度，一抹抹如条素色的被子，像要压将下来，在东方的天空
还漂浮著一座建筑物，像是宫殿之类的。往北俯视，与对山之间衔接著一个溪流，
急湍澎湃，「刷刷」有声，不知高度若何，否则大可一游而尽兴，此外，尚有一座
吊桥漂浮溪谷上。在你东边是个断崖，里面白茫茫的一片，也不知道有多深。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "down"}) );
	set( "exits", ([ 
            "south" : SAREA"mountain3",
       	    "north" : SAREA"bridge1", 
       	     "west" : SAREA"mountain1",
             "down" : SAREA"vhole1",
        ]) );
        set("goto_palace",1);
        set("can_use_flute",1);
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search()
{
    write("你发现旁边有个直径一尺的小洞(hole)指著往下(down)的方向。\n");
    return 1;
}

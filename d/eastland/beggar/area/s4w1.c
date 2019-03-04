#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "s2w1", "『薪胆村』广场" );
	set_long(@C_LONG
这是一大片黄砂广场,旁边有一颗大树。这里因为『丐帮』弟子常在此处练武
功,所以地面显得光秃秃的一根杂草也没有。有时候风刮的很大挟带著漫天的灰尘
,尤其是每当南边的高山吹著『落山风』, 真叫人眼睛睁不开。於是『丐帮』拟定
做一些水土保持的工作, 但是村里缺乏另一大片空地可以供弟子们练习,所以每次
提出做值地皮的工作就会遭人反对,於是乎人们还是得继续忍受下去。东、西和北
边是广场的继续延申, 南边则是山坡。
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"south4.c",
                      "west":DBEGGAR"s4w2.c",
	              "north":DBEGGAR"s1w1.c"
	]) );
        set("c_item_desc",([
                 "tree":"一颗大树。\n"
        ]) );
     reset();
}
void init()
{
   add_action("to_climb","climb");
}
int to_climb(string str)
{
   if (!str) return 0;
   if (str=="tree") {
       this_player()->move_player(DBEGGAR"tree1",({
            "",
            "%s从外面爬了进来。\n"}),"");
       return 1;
   }
   else {
   write("你想爬上那里呢?\n");
   return 1;
   }
}

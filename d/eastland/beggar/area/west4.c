#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "west4", "村路" );
	set_long(@C_LONG
你现在正走在一条由碎石子铺成的村 路上。村路向东、西方向延伸。村路不
很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面更开
著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心旷神
怡。鸟语蛙呜, 顿时你烦恼尽失,站在这里真是有如仙境。你的北边有一间用茅草
做的矮矮房子 ( house )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"west2.c",
                      "west":DBEGGAR"west5.c",
	]) );
        set("c_item_desc",([
              "house":"一间矮矮的房子,似乎可以进去看看 ( enter ) 。\n"
        ]) );        
    ::reset();
}
void init()
{
   add_action("to_enter","enter");
}
int to_enter(string str)
{
     if (!str) return 0;
     if (str=="house") {
         this_player()->move_player(DBEGGAR"keeper_room",({
            "%s进入了一间矮矮的房子。\n",
            "%s从外面走了进来.\n"}),"");
         return 1;
     }
     else {
     write("你想进入那里?\n");
          return 1;
     }
}                                                  
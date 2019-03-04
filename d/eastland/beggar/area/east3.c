#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "east3", "村路" );
	set_long(@C_LONG
你现在正走在一条由碎石子铺成的村 路上。村路向东、西方向延伸。村路不
很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面更开
著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心旷神
怡。鸟语蛙呜,顿时你烦恼尽失,站在这里真是有如仙境。南边有一间商店,或许你
可以进去看看是否有什麽需要的。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"east4.c",
                      "west":DBEGGAR"east2.c"
	]) );
        set("c_item_desc",([
                  "store":"一间不很大的房子,似乎可以进去看看 ( enter ) 。\n"
        ]) );
     reset();
}
void init()
{
   add_action("to_enter","enter");
}
int to_enter(string str)
{
   if (!str) return 0;
   if (str=="store") {
      this_player()->move_player(DBEGGAR"store",({
           "%s进入了一间不很大的房子。\n",
           "%s从外面走了进来.\n"}),"");
      return 1;
   }
   else {
      write("你想进入那里?\n");
      return 1;
   }
}   
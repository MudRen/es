#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
你来到了一处黑暗的洞穴，这里空洞洞地似乎没有任何东西。除此之外，你感
到这里非常潮□，空气中还有些发霉的味道，让你混身感到不舒服，或许爬上去（
climb up )会令你好过一点。
LONG
	);
        set( "exit_suppress", ({
          "nd"}) );
	set("exits", ([
          "northdown" : SAREA"hole2",
                 "nd" : SAREA"hole2"
        ]) );
	reset();
}
void init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
   if ( !arg || arg!="up" ) return notify_fail("Syntax : <climb up> \n");
   this_player()->move_player(SAREA"plain3",({
         "%s爬了上去。\n",
         "%s北边的小洞爬了上来。\n"}),"");
   return 1;
}
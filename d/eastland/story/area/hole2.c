#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
你来到了一处黑暗的洞穴，这里空洞洞地似乎没有任何东西。除此之外，你感
到这里非常潮□，空气中还有些发霉的味道，让你混身感到不舒服。在这里，不时
听到些动物的嘶吼声，其声可怖已极，更兼在地上看到一堆骸骨，说明了这实在不
是个安全的地方。北边是禁地 (forbidden_ground) ，据说，需要具备经过天神祝
福的铠甲才能安全无虞地通过。
LONG
	);
        set( "exit_suppress", ({
          "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"hole1",
          "northdown" : SAREA"spell1",
                 "su" : SAREA"hole1",
                 "nd" : SAREA"spell1"
        ]) );
        set("objects", ([
         "lion#1" : SMOB"lion1",
         "lion#2" : SMOB"lion1",
         "lion#3" : SMOB"lion1"
        ]) );          
	set("pre_exit_func",([
	 "northdown" : "do_north",
	        "nd" : "do_north"
	]) );
	reset();
}
int do_north()
{
   if ( present("white lion",this_object()) ) {
      write("\n玄天玉狮拦住了你的去路！\n\n");
      return 1;
   }
   if ( this_player()->query_temp("mounting") ) {
      write("\n请先下马，以免发生危险。\n\n");
      return 1;
   }   
   return 0;
}
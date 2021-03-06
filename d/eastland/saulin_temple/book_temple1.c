//File: book_temple1.c 藏经阁前空地

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "藏经阁前" );
       set_long( @C_LONG_DESC
你走到一条小河边，河边矗立著一栋楼阁，原来这就是大名鼎鼎的少林寺藏
经阁(library)，武林中人梦寐以求的武学宝库。你很想进去(enter)见识见识，
可是阁旁四周不起眼处三两武僧看似悠闲的站在一起，他们一定是守护藏经阁的
僧人，看他们一个个神完气足，太阳穴高高鼓起，想必都是内外兼修的高手。孤
零零的一栋藏经阁建在河边，既防火警又可防盗，实在是高明之极。
C_LONG_DESC
        );
        set( "objects",([
            "monk1" : SAULIN_MONSTER"book_guard",
            "monk2" : SAULIN_MONSTER"book_keeper"  ]));
        set_outside("eastland");
    set("exits",([
       "west"  : SAULIN"stone_path2",
       "north" : SAULIN"river_side3",
       "south" : SAULIN"river_side4",
    ]) );
    reset();
}

void init()
{
    add_action( "enter_library", "enter" );
}

int enter_library(string arg)
{
	if( !arg || arg != "library" )
   		return notify_fail("你想进哪儿去啊？\n");
 	if( (present("guardian") || present("keeper") ) && (!wizardp(this_player())) &&
 		     (!this_player()->query_temp("book_quest/step")) ) {
      tell_object(this_player(),@ENTER_LIB
你正想大摇大摆\的走进藏经阁，突然守阁僧人走了过来对你合十道：
    藏经阁为本寺重地，施主请勿擅闯 !!
他们又向你微微躬身，身上的僧衣突然股了起来，你只觉得一阵强劲
的力道向你压来，忍不住连退了三四步。
ENTER_LIB
);
      return 1;
	} else {
      tell_object(this_player(), 
      	"现在没有人再能阻止你了，你大摇大摆\的走进藏经阁。\n");
      this_player()->set_temp("book_quest/step",0);
	  this_player()->move_player(SAULIN"book_temple2","SNEAK");
	  return 1;
	}
}

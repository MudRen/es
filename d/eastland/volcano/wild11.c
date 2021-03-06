#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
这片空地只有长了一些杂草，大部份是一些大小不一的石头，你发现这里的石头似
乎和别地方好像有点差别，颜色只有红色的、黑色的，像是被火烧过的样子，地面的土
壤和你所知的火山灰所形成的土相类似，你感觉这里有点热。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest" : ONEW"wild8",
     "south" : ONEW"wild10",
     "northeast" : ONEW"wild14" ]) );
set("item_desc", ([
    "cave":"@@look_cave",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_dig","dig");
}

string look_cave()
{
  if (!this_player()->query_temp("s/check"))
    return "你想看什麽 ?\n";
  return "一个小小的地洞，里面黑黑的，看不到任何东西。\n";
}

string to_search_here()
{
  string str;
  str="当你在这地方翻天覆地时,一只老鼠突然从你前面跑过，你仔细的观察老鼠的\n"+
      "来处，发现一个老鼠洞(cave)，也许\可以挖大一点看看里面藏啥东西\n";
  this_player()->set_temp("s/check",1);
  return str;
}

int do_dig(string arg)
{
    object ob1;

    if (!this_player()->query_temp("s/check"))
       return 0;
    if (!arg || arg!="cave")
    { 
      write("你要挖石油吗？\n");
      return 1;
    };
    if (be_moved!=0)
    { 
        write("这个洞穴已经被挖过了。\n");
      return 1;
    };
    tell_object(this_player(),
         "你挖开洞旁的土石，伸手进去摸索，发现了一个银色巧克力\n"
          );
    be_moved=1;
    this_player()->delete_temp("s/check");
    ob1=new(OOBJ"s_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}

#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("小树林");
	set_long(
@LONG_DESCRIPTION
你站在一条小径上，环绕著你的是一片小树林，树木的高度约只有比你的两倍身高
再高一点，你在想经过了那麽漫长的岁月，为什麽这里的树还是这麽小呢，虽然只是小
树林，但其中也是生气勃勃，另外，你也发觉这附近的土石和别的地方比较，似乎也有
点也不一样。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "northeast" : ONEW"wild9",
     "northwest" : ONEW"wild2", ]) );
set("item_desc",([
    "rock":"@@look_rock",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_push","push");
}

string look_rock()
{
  if (!this_player()->query_temp("g/check"))
    return "你想看什麽 ?\n";
  return "这块灰色的石头上有两个凹下去的印子，彷佛是一对手掌。\n";
}

string to_search_here()
{
  string str;
  str="当你搜索这地方的时候,你发现有块石头(rock)底下闪闪发光，石头表面似忽有\n个手掌印子。\n";
  this_player()->set_temp("g/check",1);
  return str;
}

int do_push(string arg)
{
    object ob1;

    if (!this_player()->query_temp("g/check"))
       return 0;
    if (!arg || arg!="rock")
    { write(
        "你想要效法愚公移山吗？\n");
      return 1;
    };
    if (be_moved!=0)
    { write(
        "这块石头已经被移动过了。\n");
      return 1;
    };
    write("你移开石头，发现了一个蓝色巧克力\n");
    this_player()->delete_temp("g/check");
    be_moved=1;
    ob1=new(OOBJ"b_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}

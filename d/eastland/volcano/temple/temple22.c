#include "../oldcat.h"

inherit ROOM;

int be_get2,be_get3;
void create()
{
	::create();
    set_short( "神殿器物室");
	set_long( 
@LONG_DESCRIPTION
这是一间神殿器物室，左边的架子(shell)上尽是一些祭祀时所要穿戴的东西，
右边的柜子(closet)里放著一些香油蜡□之类的，还有一些碗盘碟子的器皿，地上另
外还堆了一大堆杂七杂八的物品。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple13",
     ]) );
set("item_desc",([
    "closet":"一个红木柜子，上面的漆已经差不多掉光了，里面放的是一些器皿之类的东西。\n",
    "shell":"一个铁架，在每一层的架子上都有标示这层是摆\那一类的东西，从头到脚的祭祀服装\n都放在这里。\n",
    ]) );
set("search_desc", ([
    "closet":"@@to_search_right",
    "shell":"@@to_search_left",
    ]) );
reset();
}

string to_search_right()
{
  string str;
  object ob;

  if (be_get2)
    return "你没有找到任何有用的东西。\n";
  str="\n你把柜子打开，翻了一下，找到一只小槌子。\n";
  ob=new(OOBJ"club");
  ob->move(this_player());
  be_get2=1;
  return str;
}

string to_search_left()
{
  string str;
  object ob;

  if (be_get3)
    return "你没有找到任何有用的东西。\n";
  str="\n你在架子上找了找，终於找到一块布。\n";
  ob=new(OOBJ"cloth");
  ob->move(this_player());
  be_get3=1;
  return str;
}

void reset()
{
  ::reset();
  be_get2=0;
  be_get3=0;
}

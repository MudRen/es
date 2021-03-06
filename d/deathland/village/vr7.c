
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    //set("light",1);
    set_short("The beautiful building","优美的建筑");
    set_long(@Long
Long
,@CLong
一栋优美的建筑物,是由一个外来的妖精魔法师所成居住的地方.由外表看来,这里装
饰的富丽堂皇,美仑美奂,除此之外,最能吸引住你目光的焦点莫过於一个大书柜(closet)
了,除此之外,有一个\摆\饰品与这个房间极不搭调,那就是一张好像小孩子画的画像(paint
ing),而且这画像还特别的大,只要你人在这里,你就不得不看著它.
CLong
    );
    set("c_item_desc",([
        "closet":"一个大书柜,里面的藏书惊人但是百分之九十九都是古文字,一\n"
                 "种失传已久的古妖精文,已经没有人认识了.\n",
        "painting":"画著一只妖精的画像,但是拙劣的笔法令人发笑\n",
        "bottle":"@@to_look_bottle",
        ]) );
    set("search_desc",([
       "closet":"@@to_search_closet",
       "painting":"@@to_search_painting",
        ]) );
    set("exits",([
                "east":Deathland"/village/v14",
             ]));
    set("objects",([
        "impmage":Monster"/impmage",
        ]) );
    reset();
}

string to_look_bottle()
{
  this_player()->set_explore( "deathland#27" );
  return "一个很特殊的玻璃瓶,你很惊讶为何一个小小的玻璃瓶会有这麽大的魔力.\n";     
}

string to_search_closet()
{
      return "除了一大堆的书籍外还有一个小小的空瓶子.\n";
}

string to_search_painting()
{
    return "你期望能够发现甚麽?一个隐藏在後的通道\或\是一个奇怪的按钮.\n";
}


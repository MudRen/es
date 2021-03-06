#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("矮灵族神殿");
	set_long(
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿，神殿的顶端雕有火神的图案，四根雕
有龙纹的巨大柱子竖在四个脚落，几个祈祷者正在对著火神的神像(statue)不
知道念著甚麽经文，在神像前的供桌(desk)有一些供品。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple6",
     "west": OTEMP"temple5",
     "south": OTEMP"temple1",
     ]) );
set("item_desc",([
    "statue":"一个栩栩如生的火神雕像，你感觉雕像的眼睛正在看著你\n",
    "desk" : @DESK
蜥蜴人的尾巴，半兽人的脑，鸟人的翅膀，连眼魔的触脚也在其中，跟这些比较
不同的是一碗小厨师麻辣牛肉面(beef noodle)也在供品之列。
DESK
,
    "noodle":"一碗香喷喷的牛肉面，令你食指大动。\n",
       ]));
set( "objects", ([
     "m_enforcer" : OMONSTER"m_enforcer",
     "wprayer#1" : OMONSTER"wprayer",
     "wprayer#2" : OMONSTER"wprayer",
     "corasho": OMONSTER"corasho",
     ]) );
set("light",1);
reset();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob1;

  if (!arg || (arg!="noodle" && arg!="牛肉面"))
      return notify_fail("\n你要吃仙桃吗?\n");

  if (be_eated) {
    write( "\n你拿起碗一看，发现好吃的牛肉面已经被吃掉了。\n");
    return 1;
  }

  write( "\n你趁著其他人不注意的时後，偷偷的把这碗泡面拿起来吃掉，\n");
  write( "哇!真是人间美味．．．．．突然你发现好像咬到什麽东西，敢 \n");
  write( "紧吐出来．．．．吓 !  竟然是一个金色巧克力。\n");
  be_eated=1;
  ob1=new(OOBJ"g_chocolate");
  ob1->move(this_object());
  return 1;
  
}

void reset()
{ 
  ::reset();
  be_eated=0;
}

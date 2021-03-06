#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山腰");
	set_long( 
@LONG_DESCRIPTION
那耸立云霄的火山山口似忽还会有阵阵浓烟冒出，不知何时还会再爆发，你觉的
这里非常的热，不可能有生物能在这里生存下去，这里到处都是火山岩和浮石，这座
由火山岩所构成的火山，由於到处是巨大的裂缝，因此想到达山顶是相当困难的，你
站在山腰处，在你的左方有一棵被烤乾的树木，抬头往上望去，心里想著要到达火山
顶还一大段距离，在树下休息一下吧。
LONG_DESCRIPTION
	);

/* set("search_desc",([
    "here":"@@search_here",
    ]) ); */

set( "exits", ([
     "southwest" : ONEW"varea2",
     "northwest" : ONEW"varea3" 
     ]) );
set_outside("eastland");
reset();
}

string search_here()
{
      return "\n"; 
      write( 
           "你绕著这棵树搜寻了一圈，发现有一枝干(branch)怪怪的。\n"+
           "这个枝干很有弹性，你可以试著去拉拉看。\n");
}

void init()
{
/*    add_action("do_pull","pull"); */
}

int do_pull(string arg)
{   
    if (!arg || arg!="branch")
    { write(
        "你的手做出一些奇怪的动作.....天上传来一阵笑声....你在拉什麽拉？\n");
      tell_room(this_object(),this_player()->query("c_name")+"的手做一些奇怪的动作。\n",this_player());
      return 1;
    };
    write( 
          "树干上出现一个大洞，你信步往洞中走去....\n"+
          "你刚跨入树洞之中，啊的一声，往下摔了下去...\n"+
          ".....\n\n......\n\n...\n\n..........\n\n...\n\n.....\n"+
          ".........\n\n......\n"+
          "你发现你已在火山的山腹中。\n");
    this_player()->move_player( ONEW"mcave1.c","SNEAK" );
    tell_room(this_object(),"你见到"+this_player()->query("c_name")+"消失在你的面前。\n",this_player());
    return 1;
}

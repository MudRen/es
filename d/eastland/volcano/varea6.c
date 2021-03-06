#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("火山口");
	set_long( 
@LONG_DESCRIPTION
在这火山的最顶端，在火山岩的地表之上，到处都是火山岩和浮石的石块，你站在
火山口，往下看去，火山口仍有阵阵浓烟冒出，不知何时还会再爆发，在你的右侧有一
座巨大的雕像(statue)，雕像前面有个小祭坛(altar)，祭坛上似乎还留有一点血迹，你
想这一定就是那矮灵族将祭品献给火山之神的祭台。
LONG_DESCRIPTION
	);

set("item_desc",([
    "statue" : "这是一座巨大的火神雕像，住在火山附近的矮灵族相信只有奉献鲜血才能平息火神之怒。\n",
    "altar" : "这祭坛上到处都是血迹，在台面上有一个火龙的图案(symbol)，在祭坛的下方有一个告示板(board)。\n",
    "symbol" : "一条张牙舞爪的火龙，嘴里吐著火□。\n",
    "board" : "对我奉献，你就会得到你所想要的。\n",
    ]));
set( "exits", ([
     "down" : ONEW"varea3"
     ]) );
set( "objects", ([
     "wwizard":OMONSTER"wwizard"
     ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_touch","touch");
/*    add_action("do_jump","jump"); */
}

int do_touch(string arg)
{  
    if(!arg || arg!="symbol") return 0;

    write("你看到一阵浓烟将你包围，待浓烟散去，你发现自己已到了另一个地方了。\n");
    this_player()->move_player(ONEW"wcave1","SNEAK");
    tell_room(this_object(),"你看到一阵浓烟将"+this_player()->query("c_name")+"包围起来，等浓烟散去，你已看不见"+this_player()->query("c_name")+"的人影\n",this_player());
    return 1;
}

int do_jump()
{
    write(
          "你的身体不断往下掉，你的耳边只听到咻咻声，本以为一定会死，\n"+
          "说巧不巧，刚好撞到在一凸出的树枝上，啪的一声，树枝断了但\n"+
          "也将你的坠势阻了一阻，你跌在厚厚的火山灰上。\n");
    this_player()->move_player( ONEW"icave1.c","SNEAK" );
    tell_room(this_object(),"你看到"+this_player()->query("c_name")+ "把自己当成祭品往下跳去.\n",this_player());
    return 1;
}

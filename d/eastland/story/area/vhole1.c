
#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
这是一处透著些许微光线的阴暗洞穴。从外面吹进来的风在地上绕著圈圈形成
一个小小的龙卷风旋即又飞起以其利锐的前锋刮过墙壁发出「咻咻咻」的声音；在
空中，好似有人正在对著你嘲笑并且发出桀桀的笑声，那异样的感觉，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麽东西，低头一看，竟然是一堆白骨！看
来这不是个良善的地方，你还是快离开这里为妙。
LONG
	);
        set( "exit_suppress", ({
            "down" }) );
	set("exits", ([
            "out" : SAREA"mountain2",
           "east" : SAREA"vhole3",
           "west" : SAREA"vhole2",
           "down" : SAREA"room_h"
        ]) );
        set("pre_exit_func",([
           "out":"can_pass"]));
	reset();
}
void init()
{
    add_action("do_auction","auction");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("这里受妖法控制使得你无法做这样动作！\n");
    return 1;
}
int can_pass()
{
   object vampire;
   if ( vampire=present("the great vampire",this_object()) ) {
       write(sprintf("%s伸出双手拦住你的去路！\n\n",vampire->query("c_name")));
       return 1;
   }
   return 0;
}
int clean_up()
{
   return 0;
}

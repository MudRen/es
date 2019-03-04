#include "../story.h"

inherit ROOM;
int bone=1;
int i=0;
void create()
{
        ::create();
	set_short("洞穴");
	set_long( @LONG
这是一处透著些许微光线的阴暗洞穴。从上面灌进来的风在地上绕著圈圈形成
一个小小的龙卷风旋即又飞起以其利锐的前锋刮过墙壁发出「咻咻咻」的声音；在
空中，好似有人正在对著你嘲笑并且发出桀桀的笑声，那异样的感觉，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麽东西，低头一看，竟然是一堆白骨(bone
)！看来这不是个良善的地方，你还是快离开这里为妙。
LONG
	);
	set( "exits", ([ 
       	        "up" : SAREA"vhole1",
       	      "down" : SAREA"room_t",
        ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
    add_action("do_search","search");
}
void qq()
{
    bone=1;
}
void rr()
{
   i++;
   if ( i < 2 ) return ;
   i=0;
   call_out("qq",3600);
   return ;
}
int do_search(string arg)
{
    object head,tail;
    if ( !arg || arg !="bone" ) return 0;
    if ( !bone ) {
       tell_room(this_object(),"这堆白骨已经被人找过了 ! \n");
       return 1;
    }
    tell_room(this_object(),"\n突然从白骨堆里蹦出一只妖怪来 ! \n\n");
    head=new(SMOB"head");
    tail=new(SMOB"tail");
    head->set("other",tail);
    tail->set("other",head);
    head->move(this_object());
    tail->move(find_object_or_load(SAREA"room_t"));
    bone=0;
    return 1;
}
#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿内长廊");
	set_long( @LONG
殿内长廊到这里已经是尽头，廊道往东北方向延伸。廊道白玉铺地，栏杆雕饰
精细，朱壁每尺镶嵌著拳大夜明珠，好似一条蜿延银蛇，不时发出白光，照耀著满
道通明。廊旁有几座楼阁，每座竟不知好几层，每层九间，通体碧玉砌成，琼槛瑶
阶，金门翠东，雕云缕月，气象庄严，奇丽无俦。细看前面几层，层层的陈设无不
穷极精丽，妙夺天工，於珠光宝气中现出古色古香，别有雍穆清雅之致。楼阁之中
围著一小型殿堂，通体水晶建成，白光灿烂，耀眼生辉。
LONG
	);
        set("light",1);
        set("pre_exit_func",([
           "northwest":"can_pass"]));
        set("exits" , ([
           "northeast" : SPALACE"n2",
           "northwest" : SPALACE"house1"
        ]) );
	reset();
}
int can_pass()
{
    if ( this_player()->query("palace_war") ) return 1;
    return 0;
}                            
#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之处是一溪谷里的沙岸，前面溪水从东北打个折，缓缓流向西北而去。
这溪谷两岸都是千仞高的山峰，除非胁生两翼、步纵万尺，否则断难攀越而过。这
溪谷上方不时有鸟类飞过或时而停在山壁老枯枝上引吭高歌，发出的声音引起山壁
相互共鸣。你赫然发现地上有根半截的断技，上面缠著些许白色细线，原来是一钓
根，想必这里曾经有人留连，而不是个人烟俱灭的地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
         "northwest" : SAREA"bottom1",
         "northeast" : SAREA"bottom3"
        ]) );
	reset();
}

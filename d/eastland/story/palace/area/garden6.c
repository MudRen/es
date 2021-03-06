#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("八音玲珑亭");
	set_long( @LONG
玲珑亭高两层，每一层都有四面，但一二楼层却不是吻合的，反而相差四十五
度。此亭通体由红玉建成，粉壁朱墙，镶嵌著许多造型各异，花纹多样的琉璃构件
，八脚攒尖顶，顶上贴满琉璃瓦，琉莹生辉，光彩夺目。亭内笙簧交奏，琴瑟叮冬
，丝竹之声不绝於耳，竟不知从何而来，内中八音，清铿绝殊天上人间，却不晓何
物所奏。
LONG
	);
        set("light",1);
        set("exits" , ([
               "out" : SPALACE"garden5",
        ]) );
        set("no_embattle",1);
        set("objects" , ([
              "king" : SPMOB"king1",
          "gardener" : SPMOB"gardener2",
        ]) );
	reset();
}

#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("天都大殿东侧");
	set_long( @LONG
你立足之地是天都大殿的东侧，大殿地面原是用整片翠精碧玉建成的，不但玉
质特佳，光明若镜，毛发可鉴。环顾殿内，琉璃天瓦，上下两相对照，发出七彩旋
转虹光；殿偏玉柱彩壁，左侧一金门矗立，除此之外别无它物，虽然空间广阔，却
益发显得庄严隆重，气象万千。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e2",
           "west" : SPALACE"center",
          "north" : SPALACE"n1e1",
          "south" : SPALACE"s1e1",
        ]) );
	reset();
}

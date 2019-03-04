#include "../../story.h"

inherit ROOM;

void create()
{
	::create();
        set_short("旅馆二楼");
	set("long",@LONG
这里是旅馆二楼，打扫得很乾净，并且相当安静。除了摆了一排排的床以外，
每个床旁边的桌子上还有些茶水。大多数的人都躺在床上闭目养神，少数业已休息
完毕精神饱满准备好行李等著要下楼，谁也不去打扰谁。
LONG
	);
	set("light", 1);
        set("exits",([
           "down" : SCITY"hotel1"
        ]) );
	reset();
}

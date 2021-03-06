#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山腰");
	set_long( 
@LONG_DESCRIPTION
你站在山腰处，抬头往上望去，心里想著要到达火山顶还一大段距离，休息一下
吧。那耸立云霄的火山山口似忽还会有阵阵浓烟冒出，不知何时还会再爆发，你觉的
这里非常的热，不可能有生物能在这里生存下去，这里到处都是火山岩和浮石，这座
由火山岩所构成的火山，由於到处是巨大的裂缝，因此想到达山顶是相当困难的。
LONG_DESCRIPTION
	);

set( "exits", ([
     "northeast" : ONEW"varea5",
     "north" : ONEW"varea3",
     "down" : ONEW"varea1" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

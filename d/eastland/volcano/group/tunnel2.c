#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("石室");
	set_long( 
@LONG_DESCRIPTION
你正在一个黑黝黝的石室中，这里到处是残骨断骸，血迹斑斑．．．．．．．．．
看了就教人心惊胆跳。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OGROUP"tunnel1",
     ]) );
set( "objects", ([
     "shuang":OMONSTER"shuang",
     ]) );
reset();
}

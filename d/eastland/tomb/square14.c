#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下广场");
	set_long( 
@C_LONG_DESCRIPTION
哇......这□是一个巨大的广场，在经过那麽长久的路程後，这儿令你有豁然开朗的感
觉。实在无法想像当年的工匠们是如何在地底下建立如此大的广场，你不禁对那些工匠起了
分敬意。广场上空空荡荡的，似乎没有任何生物存在，也许\早\就死光了。你看到南边似乎有
不寻常的东西。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north"  : TOMB"/square13",
		"south"  : TOMB"/square15"  ]) );
	reset();	
#include <replace_room.h>
}


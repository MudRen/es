#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下广场");
	set_long( 
@C_LONG_DESCRIPTION
这□是一个巨大的广场，在经过那麽长久的路程後，这儿令你有豁然开朗的感觉。实在
无法想像当年的工匠们是如何在地底下建立如此大的广场，你不禁对那些工匠起了分敬意。
广场上空空荡荡的，似乎没有任何生物存在，也许\早\就死光了。在南边远处好像有什麽东西
，红红的光吸引你过去探个究竟。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : TOMB"/square19",
		"east"  : TOMB"/square8",
		"west"  : TOMB"/square10"  ]) );
	reset();	
}

void init()
{
	if ( this_player()->query_temp("ORB_POOL") )
		add( "exits", ([ "down" : TOMB"/down1" ]) );
}

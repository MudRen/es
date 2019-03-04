#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」内西大街上，大街往南边方向延伸，北边则是北大街
，东边则是城中心道路，许多皇室贵族都居住在那里，往南走可达西门口。近来
西大街有凌驾东大街的趋势，日益繁华，街旁多是一排排的商铺。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nw1",
           "south" : SCITY"ww",
           "north" : SCITY"wn2",
        ]) );
	reset();
}

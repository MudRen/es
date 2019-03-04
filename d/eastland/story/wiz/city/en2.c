#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」内北大街上，大街往西边方向延伸，南边则是东大街。
由於北大街地处偏僻，往来无尘嚣，街旁树木稀稀落落於一排排的房子间，空气清
幽，显的格外清新脱落，街道内相当安静，是为居住之地。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne2",
       	   "south" : SCITY"en1"
        ]) );
	reset();
}

#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("石阶小径");
	set_long( @C_LONG_DESCRIPTION
你走在少林寺内千廊百院间的通道上，磨损得圆润光华的石阶无言的对你
夸耀少林寺的悠久历史。遥望寺外蓊郁松林，寺内黄瓦朱墙，寺僧来去、游客
相接，你不禁有出世之想。东边就是鼎鼎有名的达摩面壁处。
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
    set( "pre_exit_func", ([
    	"east" : "check_monk"
    ]) );
    set( "objects", ([
    	"monk1" : SAULIN_MONSTER"monk",
    	"monk2" : SAULIN_MONSTER"monk",
    ]) );
	set( "exits", ([
		 "east"  : SAULIN"damo_stone",
		 "west"  : SAULIN"entrance"
	]) );
	set("no_monster", 1);
	reset();
}

int check_monk()
{
	if( wizardp(this_player()) || !present("monk") ) return 0;
	tell_object(this_player(),
		"达摩堂 黑衣和尚说: 那里乃本寺圣地, 游客请止步。\n"
	);
	return 1;
}

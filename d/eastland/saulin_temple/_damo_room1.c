// File: /d/eastland/saulin_temple/damo_room1.c
// Generated by Roommaker Wed Nov 22 23:29:23 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("达摩院 明心堂");
	ob->set_long( @LONG_DESCRIPTION
走进这里，除了此起彼落的漫长呼吸声外，几乎什麽声音都没有。
好几个年轻和尚在已经被磨的光亮的青石地上或坐或躺的修习名闻天下
的少林派内功\，专心致志的他们使得这里像极了一座古墓，你不禁有些
毛骨悚然。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/eastland/saulin_temple/damo_temple" ]) );
	ob->reset();
}

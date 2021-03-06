// File: /d/eastland/saulin_temple/road3.c
// Generated by Roommaker Wed Nov 22 23:39:16 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("凉亭");
	ob->set_long( @LONG_DESCRIPTION
此处位於少室山的山腰，附近都是连绵不绝的高山，你正站在一座用
大理石制成的凉亭，这是少林寺为过往进香的旅客所造的休憩所，也是接
待武林朋友的迎宾处。由此往上望去，少林寺已清晰可见，此地已经是少
林寺的势力范围了，亭旁有一云石铺成的石阶上，宛延直上少林。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"down" : "/d/eastland/saulin_temple/road2", 
		"up" : "/d/eastland/saulin_temple/road4" ]) );
	ob->set( "objects", ([ 
		"guest" : "/d/eastland/saulin_temple/monster/guest", 
		"vendor" : "/obj/vendor", 
		"monk" : "/d/eastland/saulin_temple/monster/greet_monk" ]) );
	ob->reset();
}

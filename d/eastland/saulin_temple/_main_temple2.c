// File: /d/eastland/saulin_temple/main_temple2.c
// Generated by Roommaker Wed Nov 22 23:33:24 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("少林寺大雄宝殿前厅");
	ob->set_long( @LONG_DESCRIPTION
你现在来到了少林寺大雄宝殿的前厅，你的目光被两旁雄伟的石柱
(stonehenge)所吸引。你仰头望去，两边的墙壁上刻满了玄奘西游取经
的故事。左边墙上有一块牌子，上面密密麻麻的不知道写些什麽。前厅
的中央有一个香炉(censer)，里面鼎盛的香火显示这里是个佛教兴盛之
地。往北看去就是鼎鼎有名的大雄宝殿，南边似乎有一个很大的广场。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/saulin_temple/main_temple1", 
		"north" : "/d/eastland/saulin_temple/main_temple3" ]) );
	ob->set( "item_desc", ([ 
		"stonehenge" : @LONG_TEXT
这个石柱上雕满了龙，凤和麒麟，虽然已经历经数代，但是仍然十分的细致，可称的
上是艺术的杰作。
LONG_TEXT
, 
		"sign" : "玄慧虚空\n", 
		"censer" : "这是一个用青铜铸造的大香炉，看起来已经年代久远了，上面插满了香。\n" ]) );
	ob->set( "no_monster", 1 );
	ob->reset();
}

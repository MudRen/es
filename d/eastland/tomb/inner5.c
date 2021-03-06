#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
这儿就是传说中的陵墓了，在你头顶上竟是一片璀璨的星空，众星们是用金钢钻做的，
而一轮明月则是一块皎洁无瑕的碧玉，冷冷的银光自星空洒下。在你南边躺著的是缩小版的
东方大陆 !! 地形山川、树木建筑无不维妙维肖，河流中甚至还有水在缓缓流动著，真是太
惊人了，不知道前人是如何创造出这般景象，委实令人敬佩。北边是一片巨大、鲜绿色的翡
翠(jade)，隐约透出阵阵的红光，大概是有什麽宝物吧。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"east"  : TOMB"/inner4",
		"west"  : TOMB"/inner6"  ]) );
	set( "item_desc", ([
		"jade" : "这是一片巨大的翡翠，从它那完美无瑕的鲜绿色可以知道它的\n"
			 "品质有多好。你注意到旁边有滑动过的痕迹，也\许\你可以试著\n"
			 "推推(push)看。\n" ]) );
	reset();	
}

void init()
{
	add_action( "do_push" , "push" );
}

int do_push(string str)
{
	object who;
	who = this_player();
	
	if ( !str || str == "" ) return notify_fail("推啥？\n");
	if ( str == "jade" || str == "door" ) {
		if ( (int)who->query_stat("str") < 15 ) 
			return notify_fail("你使尽吃奶的力气，还是推不动它。\n");
		if ( (int)who->query_stat("pie") < 15 )
			return notify_fail("你听到一股声音说道：不够诚心正意的人是无法进入的 !!\n");
		tell_object(who,
			"你轻轻地一推，翡翠便向外滑开。你进入了一个新的石室中。\n" );
		tell_room(this_object(),
			sprintf("%s将翡翠推开，走了进去。那翡翠随即恢复原状。\n",
				who->query("c_cap_name")) , who );
		tell_room(TOMB"/inner9",
			sprintf("%s将翡翠推开，走了过来。那翡翠随即恢复原状。\n",
				who->query("c_cap_name")) , who );
		who->move_player(TOMB"/inner9","SNEAK");
		return 1;
		}
	return notify_fail("推啥？\n");
}
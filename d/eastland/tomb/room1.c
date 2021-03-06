#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下石室");
	set_long( 
@C_LONG_DESCRIPTION
你进入了一个宽阔的石室，这儿似乎是迷宫的终点。四周的墙壁是用上好石砖砌成的，
在房间的中央有四支柱子，柱上彩绘了栩栩如生的巨龙。包围在柱子中央的是一座看似祭坛
的东西，上面雕铸了奇异的文字(writings)，看来年代相当久远了。左边墙角似乎有什麽东
西，但是你看不清楚。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/room4", 
		"south" : TOMB"/maze10",
		"east"  : TOMB"/room2",
		"west"  : TOMB"/room3"  ]) );
	set( "exit_suppress" , ({ "west", }) );
	set( "pre_exit_func", ([
		"west" : "check_WALL" ]) );		
	reset();	
}
void init()
{
	add_action( "do_look", "look");
	add_action( "do_search", "search");
}

int do_look (string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "")
	return notify_fail(" 看啥 ??\n");
	
	if ( str == "writings" ) {
		if ( (int)player->query_skill("runes") > 50 ) {
			tell_object( player, 
			"『  洞天福地  』\n" );
			return 1; }
		else 
			tell_object( player, 
				"你觉得眼花撩乱，看不清楚这些字。\n" );
				return 1;
	}
	if ( str == "west" ) 
		return 1;
	return 0;
}

int do_search(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "" )
		return notify_fail("Search what??\n");
	
	if ( str == "corner" ) {
		tell_object( player, 
			"当你仔细搜寻墙角，发现西边有个小暗门可以进入!!\n"
			);
	        player->set_temp("WALL",1);
	return 1; }
	else return 0;
}

int check_WALL()
{
	object player;
	
	player = this_player();
	
	if ( player->query_temp("WALL") ) {
		player->delete_temp("WALL");
		return 0; }
	else return 1;
}
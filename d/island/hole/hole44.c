#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "地下王宫" );
	set_long(@LONG
你现在所站的的位置是蜥蜴人王宫的第二层，不过怎麽看都不像
是个达官贵人的栖息场所，倒不如说是个洞穴更为恰当；或许这是因
为蜥蜴人天生就比较不讲究居住环境所造成的。再往下就是蜥蜴人领
袖『古兹曼』的住所。
LONG
	);
	set( "exits",([
			"south" : HOLE"hole42",
			"down" : HOLE"hole45",
			]) );
	set( "objects",([
			"guard#1" : HMONSTER"life_guard",
			"guard#2" : HMONSTER"life_guard",
			]) );
	set( "pre_exit_func",([ "down" : "check_invis" ]) );
	reset();
}

int check_invis()
{
	object player;
	string him;
	
	player=this_player();
	him=player->query( "c_name" );
	if( (int)player->query( "player_invisible" )==1 )
	{
	if( present( "guard",environment(player) ) ){
	tell_room( environment(player),set_color(
	"守卫怒言道：『偷偷摸摸地想干嘛？当我俩是死人啊？』\n","HIR") );
	return 1;
	}
	else{
	tell_room( environment(player),set_color(
	"突然一道宏亮的声音说：『别以为隐形就可以逃过我的法眼，乖乖现形吧。』\n","HIR") );
	return 1;
	}
	}
	return 0;
}

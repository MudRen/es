#include "ruin.h"
inherit ROOM;

#define MIN_GARGOYLES 6

void create()
{
	::create();
	set("light", 0);
    set_short("地洞");
    set_long(@CLong
你向上一望, 洞口很小, 似乎这个洞穴很深。你很惊讶你竟然没有受
伤, 拍拍身上的灰尘, 开始观察四周... 这里的布置: 两排古老的石雕像
、散乱倒在地上的石块、仅馀半截立在地上的石柱群。和遗迹入口简直一
模一样, 但是你感到有一些不太对劲... 你仔细一看... 吓然发现: 「那
不是雕像, 是活生生的... 」
CLong
    );
    set("mob_storage", MIN_GARGOYLES);
  	reset();
}

void init()
{
	add_action("climb_up", "climb");
}

int climb_up(string arg)
{
	int skill;
	object player;
	if( !arg || !(arg == "out" || arg == "up") )
		return notify_fail("Climb what?\n");
	player = this_player();
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(65) < skill ) {
      tell_object( player, "你小心翼翼的爬了出去。\n" );
      tell_room( environment(player),
        player->query("c_name")+"爬了出去。\n" , player );
      player->move_player( RUIN"entry", "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"突然从地下钻了出来。\n", player
      );
      player->set_explore("noden#18");
    } else {
      tell_object( player,"你尝试著爬出去，结果又滑了下来。\n" );
      tell_room( environment(player),
        player->query("c_name")+"尝试著爬出去，结果又滑了下来。\n" , player
      );
    }
    return 1;
}

int is_a_gargoyle(object mob)
{
	if( (string)mob->query("name") == "Gargoyle" ) return 1;
	return 0;
}

void reset()
{
	int i;
	object *gargoyles;
	gargoyles = filter_array(
		all_inventory(this_object()), "is_a_gargoyle", this_object() );
	for( i=sizeof(gargoyles); i<query("mob_storage"); i++ )
		new(MOB"gargoyle")->move(this_object());
	::reset();
}

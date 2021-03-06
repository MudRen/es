#include "ekravia.h"
inherit BASE_ROOM;

int		room_working;

void	create()
{
	::create();
	set_light(1);
	set_short("旅馆房间");
	set_long(
@CLong
这里是旅馆的客房。首先映入眼帘的是一张木制的大床, 上面整齐地
铺著洁白的床单、棉被与一个大枕头。看来虽是平淡无奇, 但据称只要在
这张床上面睡一个晚上, 所有的外伤都可以不药而愈。
    床旁边是一张小桌子, 上面摆\了一面镜子与一盏油灯。在床的另一侧
则是一个大衣橱。其他还有一些家具, 但睡眼惺忪的你无暇看那麽多了。
CLong
);
	set("exits", ([
		"out"		: HERE"corridor2",
		]));
}

void	init()
{
	int		sleep_time;

	::init();
	if (!room_working)
	{
		room_working = 1;
		call_out( "do_sleep", 2, this_player() );
		sleep_time = random(60) +60;
		call_out( "wake_up", sleep_time, sleep_time, this_player(), 
			this_object() );
	}
}

void	do_sleep(object ob)
{
	if (ob) {
		tell_object( ob, "你往床上一躺, 不久便沈沈地睡著了\n" );
		ob->set_temp("block_command", 1);
	}
}

void	wake_up(int time, object ob, object this_room)
{
	object	key;

	if (ob) {
		ob->add( "hit_points", time*3/2 );
		if ( ob->query("hit_points") > ob->query("max_hp") )
			ob->set("hit_points", ob->query("max_hp") );
		ob->add( "spell_points", time*2 );
		if ( ob->query("spell_points") > ob->query("max_sp") )
			ob->set( "spell_points", ob->query("max_sp") );
		ob->add( "talk_points", time*4 );
		if ( ob->query("talk_points") > ob->query("max_tp") )
			ob->set( "talk_points", ob->query("max_tp") );
		ob->add( "medication_resistance", -time*5 );
		if ( ob->query("medication_resistance") < 0 )
			ob->set( "medication_resistance", 0 );
		ob->set_temp("block_command", 0);
		tell_object( ob, "你一觉醒来, 感觉体力完全恢复了。\n" );
		tell_object( ob, "你打开房门走下楼\n\n" );
		ob->move_player(HERE"corridor2", "", "out");
		key = present( "copper key", ob);
		if ((key) && (base_name(key) == OBJ"tavern_key")) 
			key->remove();
		key = present( "silver card", ob);
		if ((key) && (base_name(key) == OBJ"silver_card")) 
			key->use_card();
		this_room->remove();
	}
}
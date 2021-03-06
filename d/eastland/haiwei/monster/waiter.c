#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "waiter", "店小二" );
	set_short( "店小二" );
	set_long(
		"店小二说: 客倌请里面坐！\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "dex", 5 );
	set_skill( "dodge", 30 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 8 );
	set( "wealth/copper", 100 );
	set( "chat_chance", 50 );
	set( "att_chat_output", ({
		"店小二说道: 大爷饶命 ....\n",
		"店小二说道: 我这是招谁惹谁了 ....\n",
		"店小二左闪右躲，说道: 拜托拜托，有话好说！\n"
	}) );
#include <replace_mob.h>
}

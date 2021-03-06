#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "perichy", "裴瑞琪" );
	add( "id", ({ "artist", "court artist" }) );
	set_short( "宫廷画家裴瑞琪" );
	set_long(@CLONG
裴瑞琪是诺达尼亚王宫中最年轻的宫廷画师，她正在计画这几个月要到
东方去旅行。
CLONG
	);
	set( "race", "daemon" );
	set( "gender", "female" );
	set( "natural_weapon_class1", 24 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 15 );
	set( "alignment", 600 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 70 );
	set_skill( "longblade", 70 );
	set( "exp_reward", 2200 );
}

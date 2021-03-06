#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "wolf", "暴狼" );
	set_short( "巴斯格的宠物--暴狼" );
	set_long(
		"你看到一只非常巨大且凶恶的暴狼，对著你张牙舞爪。\n"
	);
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set_skill( "dodge", 70 );

	set( "unit", "只" );
        set_natural_armor(60,25);
	set_natural_weapon( 15, 10, 20 );

	set_c_verbs( ({ "%s用前爪扑向%s", "%s张开满口利齿的嘴，往%s咬去" }) );
	set_c_limbs( ({ "头部", "身体", "尾巴", "腿部" }) );
#include <../replace_mob.h>
}

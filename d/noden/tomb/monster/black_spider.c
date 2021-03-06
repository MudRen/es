#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "black spider", "黑蜘蛛" );
	add( "id", ({ "spider" }) );
   set_short( "黑蜘蛛" );
	set_long(
		"你看到一只黑色的大蜘蛛，这种蜘蛛并不会结网，它们是专靠快速的行动\n"
		"与强有力的肢体捕食小动物，这只蜘蛛的体型颇大，它看起来好像饿了。\n"
	);
   set("race","insect");
	set_perm_stat( "str", 2 );
	set( "alignment", -300 );
	set( "aggressive", 1 );

	set( "unit", "只" );
	set_c_verbs( ({ "%s张著两只大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺" }) );
	set_c_limbs( ({ "头部", "身体", "腿部" }) );
}

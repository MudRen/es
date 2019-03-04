#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "duck", "鸭子" );
	add( "id", ({ "duck" }) );
	set_short( "鸭子" );
	set_long(
		"农家养的鸭子, 有著短短的脖子与黑色的羽毛。\n"
	);
	set( "unit", "只" );
	set_c_limbs( ({ "的脚", "头部", "身体" }) );
	set_c_verbs( ({ "%s往%s一啄", "%s振翅往%s撞去" }) );
}

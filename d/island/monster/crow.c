#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "black crow", "乌鸦" );
	add( "id", ({ "crow" }) );
	set_short( "乌鸦" );
	set_long(@LONG
这只乌鸦非常吵，让你有一股把它一脚踹死的冲动。
LONG
	);
	set_perm_stat( "dex", 3 );

	set( "unit", "只" );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
	set_c_verbs( ({ "%s往下俯冲，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
}

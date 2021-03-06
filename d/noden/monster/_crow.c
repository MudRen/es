#include <mudlib.h>

void create(object ob)
{
	if (!ob ) return ;
	ob->set_level(1);
	ob->add( "id", ({ "crow" }) );
	ob->set_name( "black crow", "乌鸦" );
    ob->set_short( "乌鸦" );
	ob->set_long(
		"这只乌鸦非常吵，让你有一股把它一脚踹死的冲动。。\n"
	);
	ob->set_perm_stat( "dex", 3 );

	ob->set( "unit", "只" );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 5 );
	ob->set_c_verbs( ({ "%s往下俯冲，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	ob->set_c_limbs( ({ "头部", "身体", "翅膀" }) );
}

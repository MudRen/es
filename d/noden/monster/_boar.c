#include <mudlib.h>

void create(object ob)
{
    if (!ob ) return ;
	ob->set_level(3);
	ob->set_name( "fat boar", "野猪" );
	ob->add( "id", ({ "boar" }) );
   ob->set_short( "野猪" );
	ob->set_long(
		"这头野猪实在很胖，胖到你几乎把它误认为别人饲养的猪。\n"
	);
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 2 );
   ob->set( "race", "beast" );
	ob->set( "unit", "头" );
	ob->set( "natural_weapon_class1", 7 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 8 );
	ob->set_c_verbs( ({ "%s低头猛冲，撞向%s", "%s在地上一滚，用牙齿往%s顶去" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部", "屁股" }) );
}

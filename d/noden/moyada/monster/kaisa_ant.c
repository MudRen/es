#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("Kaisa ant", "凯萨之蚁");
	add( "id", ({ "ant" }) );
	set_short("凯萨之蚁");
	set_long(
		"十分巨大的蚂蚁，两片牙齿就像镰刀一样锋利。\n"
	);
	set( "max_hp",500);
	set( "hit_points",500);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 700 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 80, 35 );
	set_perm_stat("str",28);
	set_perm_stat("dex",20);
	set_perm_stat("con",30);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一声，抖了几下不动了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "脚" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
	set( "exp_reward", 8500 );
}

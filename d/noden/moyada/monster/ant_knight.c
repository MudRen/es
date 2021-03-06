#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("ant knight", "骑士蚁");
	add( "id", ({ "ant" }) );
	set_short("骑士蚁");
	set_long(
		"骑士蚁是比兵蚁更具战力的巨蚁，光看那两片巨大的牙齿就令你心寒。\n"
	);
	set( "max_hp",250);
	set( "hit_points",250);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 200 );
	set_natural_weapon( 26, 11, 22 );
	set_natural_armor( 49, 20 );
	set_perm_stat("str",24);
	set_perm_stat("dex",21);
	set_perm_stat("con",24);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一声，抖了几下不动了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "脚" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
}

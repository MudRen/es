#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "fat rat", "胖老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "胖老鼠" );
	set_long(
		"一只极肥的大老鼠，看起来像是一头猪。\n"
	);
	set_perm_stat("dex", 2 );
	set_perm_stat("str", 5 );

	set_c_verbs( ({ "%s用爪子乱抓%s", "%s张嘴往%s咬下" }) );
	set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );

	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 4 );
	set( "max_hp", 50 );
	set( "hit_points", 50 );
}

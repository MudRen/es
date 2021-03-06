#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "grey rat", "灰老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "灰老鼠" );
	set_long(
		"一只又大又肥的灰老鼠，看起来很脏。\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 3 );
	set_c_verbs( ({ "%s用爪子乱抓%s", "%s张嘴往%s咬下" }) );
	set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );

	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 2 );
}

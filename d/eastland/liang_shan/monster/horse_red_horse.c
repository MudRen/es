#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(14);
	set_name( "red_horse", "红鬃烈马" );
	add( "id", ({ "horse" }) );
	set_short( "红鬃烈马" );
	set_long(
		"一只红色的小马，但它的脾气似乎不太好。\n" );
	set( "unit", "只" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set( "natural_armor_class", 45 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 30 );
	set( "alignment", 10 );
	set( "max_load", 2300 );
	set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
	set_c_verbs( ({  "%s扑动前蹄，向前直击%s", "%s红尾巴一甩，一团红云扫向%s" }) );

}

void init()
{
//	monster::init();
	mount::init();
}

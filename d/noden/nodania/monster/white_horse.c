#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(11);
	set_name( "white horse", "白色马" );
	add( "id", ({ "horse" }) );
	set_short( "白色马" );
	set_long(
		"这是一匹高大、强壮的白色马，通常以白马为座骑的骑士地位都不低。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 7 );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 19 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 21 );
	set( "alignment", 100 );
	set( "max_load", 2100 );
	set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起来，用前肢在%s一阵上乱蹬" }) );

	equip_armor("/d/noden/nodania/obj/mithril_saddle" );
}

void init()
{
//	monster::init();
	mount::init();
}

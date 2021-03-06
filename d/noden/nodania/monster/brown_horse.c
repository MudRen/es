#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	object saddle;

	::create();
	set_level(6);
	set_name( "brown horse", "棕色马" );
	add( "id", ({ "horse" }) );
	set_short( "棕色马" );
	set_long(
		"这是一匹高大、强壮的棕色马。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 10 );
	set( "alignment", 100 );
	set( "max_load", 1900 );
	set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起来，用前肢在%s一阵上乱蹬" }) );

	saddle = new( "/d/noden/nodania/obj/leather_saddle" );
	saddle->move( this_object() );
	equip_armor( saddle );
}

void init()
{
//	monster::init();
	mount::init();
}

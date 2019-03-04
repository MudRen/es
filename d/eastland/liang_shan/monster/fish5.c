#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("grass carp", "草鱼");
	add("id",({"fish","carp"}) );
	set_short("草鱼");
	set_long(
		"这是一条褐黄色的草鱼，无须，背暗腹白，鱼唇极为粗糙，以水\n"
		"边的禾草为主食。\n"
	);
	set( "unit", "条" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );
	set_skill("swimming",100);
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}


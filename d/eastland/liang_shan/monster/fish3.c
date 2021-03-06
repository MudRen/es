#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("golden carp", "鲫鱼");
	add("id",({"fish","carp"}) );
	set_short("鲫鱼");
	set_long(
		"这是一条淡黄色的鲫鱼，渔夫们又叫它土鲫，大概是因为它是底生\n"
		"动物食性，其肉怎麽煮都带土味之故。\n"
	);
	set( "unit", "条" );
	set( "likefish",1);
	set( "alignment", 300 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}


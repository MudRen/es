#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("Chinese catfish", "鲶鱼");
	add("id",({"fish","catfish"}) );
	set_short("鲶鱼");
	set_long(
		"鲶鱼体扁而延长，头部巨大，呈圆锥状，以小水生动物为主食，\n"
		"若以清汤煮食，十分味美。\n"
	);
	set( "unit", "条" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 9 );
	set_skill("swimming",100);
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}


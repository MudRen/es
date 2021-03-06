#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("top-minnow", "大肚鱼");
	add("id",({"fish"}) );
	set_short("大肚鱼");
	set_long(
		"头部及体侧都有大圆鳞，眼大口小头尖，上下颔有细齿聚成齿带，\n"
		"杂食性，环境适应性高。\n"
	);
	set("likefish",1);
	set( "unit", "条" );
	set( "alignment", -100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 1 );
	set( "natural_max_damage1", 3 );
	set_skill("swimming",100);
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}


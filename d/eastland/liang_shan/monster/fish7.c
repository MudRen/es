#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("swamp eel", "鲈鳗");
	add("id",({"fish","eel"}) );
	set_short("鲈鳗");
	set_long(
		"这是一条巨大的鲈鳗，浑身都是不规则的云状斑，体色颇深，\n"
		"牙齿尖细但锐利，东方人多相信鳗鱼有滋补强身的特殊功\用。\n"
	);
	set( "unit", "条" );
	set( "likefish",1);
	set( "pursuing",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 13 );
	set_skill("swimming",100);
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}


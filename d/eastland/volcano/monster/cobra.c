#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("cobra", "眼镜蛇");
	set_short("眼镜蛇");
	set_long(
		"这条眼镜蛇是相当危险的，它正盘在那儿，口吐蛇信。\n"
	);
	set( "unit", "条" );
	set( "alignment", -500 );
        set( "killer", 1);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "头部", "身体", "尾巴" }) );
	set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()),
		"眼镜蛇从嘴巴喷出一股白色的毒液，刚好喷在你的面前 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 8 );
	return 1;
}

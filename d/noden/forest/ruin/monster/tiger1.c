#include "../ruin.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "earless tiger", "无耳虎" );
	add( "id", ({ "tiger" }) );
	set_short( "无耳虎" );
	set_long(@C_LONG
一只凶猛的老虎, 不知为何, 它失去了应有的一对耳朵。
C_LONG
	);
	set("unit","只");
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "int", 10 );
	set_skill("unarmed", 70 );
	set_skill("dodge", 70);
	set("aggressive", 1);
	set("killer", 1);
	set("max_hp", 600);
	set("hit_points", 600);
	set("special_defense", ([ "all":35, "none":20, ]) );
	set("aim_difficulty",
		([ "critical":45, "vascular":55, "weakest":25, "ganglion":60 ]) );
    set_natural_armor( 60, 15 );
    set_natural_weapon( 60, 10, 25 );
	set("alignment", -500 );

	set_c_verbs( ({ "%s凶猛地向%s一口咬去", "%s迅速地扑向%s" }) );
	set_c_limbs( ({ "的头", "的身体", "的脚" }) );
}

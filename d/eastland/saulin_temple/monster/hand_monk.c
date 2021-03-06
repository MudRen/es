#include "saulin_monk.c"

void create()
{
	::create();
	set_level(11);
	set_name( "fist monk", "掌法僧" );
	add ("id", ({ "monk", "fist", }) );
	set_short( "掌法僧" );
	set_long(@DESC
他是一个中年和尚，因为他研习基本武学已有小成，现在更进一步修练掌法，
他正仔细的思考发出的掌力要如何才能挥控潇洒、运用自如。
DESC
	);
	set("alignment", 200);
	set("gender", "male");
	set("race", "human");
	set("unit", "位");
	set_perm_stat( "kar", 16 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set( "wealth/silver", 65 );
	set("special_defense", ([ "all" : 25, "none" : 10 ]) );
	set("aim_difficulty", ([ "critical" : 20, "vascular": 10 ]) );
        set_skill("unarmed",75);
	set_skill("parry",75);
        set("max_hp", 350);
        set("max_fp", 800);
        set("hit_points", 350);
        set("force_effect", 2);
        set("force_points", 800);
	set("attack_skill",FIST"wei_to");
        set("gonfus/wei_to",60);
        set_natural_weapon( 16, 9, 16 );
        set_natural_armor( 55, 24 );
}

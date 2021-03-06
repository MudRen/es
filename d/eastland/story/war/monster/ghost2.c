#include "../../story.h"

inherit WMOB"warmob";

void create()
{
	::create();
	set_level(14);
	set_name( "special ghost", "魅鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魅鬼" );
	set_long(@LONG
一个类似人的脸和野兽的身躯的影子，黑朦朦的令人看不清楚它的形体是什麽。魅
鬼是属於阵前小兵，只是那种摇旗呐喊的材料。
LONG
	);
	set( "unit", "个" );
	set( "race","鬼");
	set( "alignment", -300 );
	set_natural_armor(40,25);
        set( "special_defense", ([ "all":10 ]) );
        set( "aim_difficulty",
           ([ "critical":10, "vascular":10, "weakest":20 ]));
	set( "wealth/silver", 110 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 60 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_natural_weapon(5,4,5);
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set( "chat_chance", 5 );
	set( "att_chat_output", ({
		"魅鬼说道：别再做顽强的抵抗了，没人挡得住蚩尤大军的！\n"
	}) );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}

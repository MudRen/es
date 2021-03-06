#include "../../story.h"

inherit WMOB"warmob";

void create()
{
	::create();
	set_level(14);
	set_name( "special ghost", "魑鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魑鬼" );
	set_long(@LONG
一个类似人的脸和野兽身躯的影子，黑朦朦的令人看不清它究竟是什麽。它似乎对
著你张牙舞爪，不住发出嗡嗡的声音。
LONG
	);
        set( "race", "鬼");
	set( "unit", "个" );
	set( "alignment", -300 );
	set_natural_armor(70,15);
        set( "special_defense", ([ "all":10 ]) );
        set( "aim_difficulty",
           ([ "critical":10, "vascular":10, "weakest":20 ]));
	set( "wealth/silver", 110 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 60 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set( "chat_chance", 5 );
	set( "att_chat_output", ({
		"魑鬼说道：别再做顽强的抵抗了，没人挡得住蚩尤大军的！\n"
	}) );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"魑鬼口吐阵阵黑色的气体！!\n");
    hurt_all("evil",30);
    return 1;    
}

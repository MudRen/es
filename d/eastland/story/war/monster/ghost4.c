#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(16);
	set_name( "special ghost", "魍鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魍鬼" );
	set_long(@LONG
魉鬼长的像个三岁娃娃，通身黑□透红，长耳朵，红眼睛，乌黑光□的长头发，喜
欢学人说话的声音来迷惑人。魍鬼和魅鬼一样都惧怕龙的声音，话虽如此，它一样
不好惹。
LONG
	);
	set( "unit", "个" );
        set( "race","鬼");
	set( "alignment", -300 );
	set_natural_armor(50,25);
	set_natural_weapon(20,7,11);
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set( "aim_difficulty",
           ([ "critical":20, "vascular":20, "weakest":20 ]));
	set( "wealth/silver", 200 );
	set( "killer", 1 );
	set( "pursuing",1);
        set( "unbleeding",1);
        set( "moving",1);
        set( "speed",30);
        set( "war_points", 130 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry",60 );
	set_skill( "dodge", 60 );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"魍鬼口发鸣鸣的声音！\n");
    (CONDITION_PREFIX + "confused")->apply_effect( victim, 10, 7 );          
    hurt_all("evil",30);
    return 1;    
}

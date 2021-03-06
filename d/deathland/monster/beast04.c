#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    
	::create();
	set_level(10);
	set_name( "Hand of Underswamp", "沼泽下的魔手" );
	add("id",({"hand"}));
	set_short( "沼泽下的魔手" );
	set_long(
		"藏在沼泽下的奇怪生物, 随时都可能伸出手来拖你下沼泽里去.\n"
	);
	set( "alignment",-500 );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "str", 11 );
	set_perm_stat( "kar", 16 );
        set_natural_armor(45,5);
 	set_natural_weapon(20,11,28);
    set( "special_defense", (  [ "all":40 , "none": 35 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
	
	set("speed",10);
	set_c_limbs( ({  "手" }) );
	set_c_verbs( ({ "%s用它的手向%s捉去" }) );
    
}

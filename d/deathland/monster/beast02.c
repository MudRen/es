#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(18);
	set_name( "Beast of Swamp", "ÕÓÔóÊØ»¤ÊÞ" );
	add("id",({"beast"}));
	set_short( "Beast of Swamp", "ÕÓÔóÊØ»¤ÊÞ" );
	set_long(
		"a great beast protecting the swamp.\n",
		"Ò»Ö»ÊØ»¤Öø»Ò°µµºÕÓÔóµÄ¾Þ´óÊ¥ÊÞ.\n"
	);
	set( "alignment", 800 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 25 );
	set_skill( "dodge", 100 );
	set_natural_armor(85,10);
 	set_natural_weapon(40,25,30);
    set( "special_defense", (  ["all":25, "none": 25]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("wealth", ([ "gold": 100]) );
    set( "tactic_func", "my_tactic");
    
    item=new(Deathland"/object/crystal02");
    item->move(this_object());
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "ÊØ»¤ÊÞÍ»È»Ò§Äã.\n" );
      tell_room(environment(this_object()),
          "ÊØ»¤ÊÞÍ»È»Ò§"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 35 + random(25) );
      report(this_object(),victim);
      return 1;
      }
}

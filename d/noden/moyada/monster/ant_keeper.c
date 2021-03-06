#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("ant keeper", "蚁老板");
	add( "id", ({ "ant" }) );
	set_short("蚁老板");
	set_long(
		"蚁穴酒店的老板，肥肥壮壮的样子，让人看了就怕。\n"
	);
	set( "max_hp",140);
	set( "hit_points",140);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", -100 );
	set_natural_weapon( 13, 6, 12 );
	set_natural_armor( 28, 5 );
	set_perm_stat("str",10);
	set_perm_stat("dex",7);
	set_perm_stat("con",10);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一声，抖了几下不动了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "脚" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "tactic_func", "call_help");
	set( "alt_corpse", MOYADA"obj/ant_corpse2" );
}

int is_a_ant(object obj)
{
   if( (string)obj->query("race")=="insect" ) return 1;
   return 0;
}

int call_help()
{
    object victim, env, obj, *ants;
    int i;
    victim = query_attacker();
    env = environment( this_object() );
    
    if( !victim ) return 0;
    ants = filter_array( all_inventory( env ), "is_a_ant", this_object() );
    i = sizeof( ants );
    while( i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    return 0;
}

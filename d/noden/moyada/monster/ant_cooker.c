#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name("ant cooker", "蚁厨师");
	add( "id", ({ "ant" }) );
	set_short("蚁厨师");
	set_long(
	"一个正在忙著准备食物的厨师，看它忙进忙出的样子，生意似乎很好。\n"
	);
	set( "max_hp",100);
	set( "hit_points",100);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 20 );
	set_natural_weapon( 8, 4, 8 );
	set_natural_armor( 20, 4 );
	set_perm_stat("str",5);
	set_perm_stat("dex",5);
	set_perm_stat("con",5);
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

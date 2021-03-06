#include "../moyada.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("ant baby", "小蚂蚁");
	add( "id", ({ "ant", "baby", }) );
	set_short("小蚂蚁");
	set_long( "怪蚁的婴孩。\n"
	);
   set( "race", "insect" );
	set( "max_hp",20);
	set( "hit_points",20);
	set( "unit", "只" );
	set( "alignment", 100 );
	set( "weight", 100);
	set_natural_weapon(2, 3, 5);
	set( "c_death_msg", "%s尖叫一声，抖了几下不动了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "脚" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "tactic_func", "call_help");
    set( "exp_reward", 40 );
   set( "alt_corpse", MOYADA"obj/ant_corpse2" );
}

int is_a_ant(object obj)
{
   if( (string)obj->query("race")=="insect" ) return 1;
   return 0;
}

int call_help()
{
    object victim, obj, env, *ants;
    int i, number, left;
    
    victim = query_attacker();
    env = environment( this_object() );
    if( !victim ) return 0;
    
    ants = filter_array( all_inventory( env ), "is_a_ant", this_object() );
    number = sizeof(ants);
    i = number;
    while( i>0 && i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    left = env->query("ant_left");
    if( random(20)>5 || number > 4 || left < 1 ) return 0;
    tell_room( env,
      "小蚂蚁叫出战士蚁来帮忙抵抗。\n", this_object()
    );
    left--;
    env->set("ant_left", left);
    obj = new( MOYADA"monster/ant_solider" );
    obj->move( environment(this_object()) );
    obj->kill_ob(victim);
    return 1;
}

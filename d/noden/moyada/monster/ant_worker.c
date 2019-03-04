// /d/noden/monster/snake.c

#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("ant worker", "����");
	add( "id", ({ "ant" }) );
	set_short("����");
	set_long(
		"һֻ���ڹ����Ĺ��ϡ�\n"
	);
	set( "max_hp",40);
	set( "hit_points",40);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 50 );
	set( "weight", 100);
	set( "natural_weapon_class1", 7 );
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	set( "tactic_func", "call_help");
    set( "exp_reward", 40 );
    set( "alt_corpse", "/d/noden/moyada/obj/ant_corpse2" );
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
    while( i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    left = env->query("ant_left");
    if( random(20)>4 || number > 6 || left < 1 ) return 0;
    if( random(10) > 7 ) {
      tell_room( env, 
        "���Ͻг���������æ�ֿ������ߡ�\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_worker");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    } else if( random(10)>5 ) {
      tell_room( env, 
        "���Ͻг����ϳ�����æ�ֿ������ߡ�\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_fighter");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    } else {
      tell_room( env, 
        "���Ͻг�ɱ���ϳ�����æ�ֿ������ߡ�\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_killer");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    }
    return 1;
}

#include "../moyada.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("ant baby", "С����");
	add( "id", ({ "ant", "baby", }) );
	set_short("С����");
	set_long( "���ϵ�Ӥ����\n"
	);
   set( "race", "insect" );
	set( "max_hp",20);
	set( "hit_points",20);
	set( "unit", "ֻ" );
	set( "alignment", 100 );
	set( "weight", 100);
	set_natural_weapon(2, 3, 5);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
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
      "С���Ͻг�սʿ������æ�ֿ���\n", this_object()
    );
    left--;
    env->set("ant_left", left);
    obj = new( MOYADA"monster/ant_solider" );
    obj->move( environment(this_object()) );
    obj->kill_ob(victim);
    return 1;
}

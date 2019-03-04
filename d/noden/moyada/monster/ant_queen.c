#include "../moyada.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name("Ant Queen", "�Ϻ�");
	add( "id", ({ "ant", "queen" }) );
	set_short("�Ϻ�");
	set_long(
		"����֮����ӵ��ʮ���Ӵ����������ͣ�Ĳ������ѡ�\n"
	);
	set( "max_hp",600);
	set( "hit_points",600);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 1000 );
	set_natural_weapon( 38, 20, 30 );
	set_natural_armor( 85, 45 );
	set_perm_stat("str",23);
	set_perm_stat("dex",10);
	set_perm_stat("con",30);
	set( "weight", 900);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	set( "tactic_func", "call_help");
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
	set( "exp_reward", 14000 );
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
      if( !ants[i]->query_attackers() ) {
        tell_room( env, 
          ants[i]->query("c_name")+"��: Ϊ�������ǵ�����ս!\n"
          , ants[i]
        );
        ants[i]->kill_ob(victim);
      }
    return 0;
}

void die()
{
	object killer;

	killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#5");
	::die();
}

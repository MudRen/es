#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("ant waiter", "������");
	add( "id", ({ "ant" }) );
	set_short("������");
	set_long(
		"һ������æ��׼��ʳ������ߡ�\n"
	);
	set( "max_hp",110);
	set( "hit_points",110);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 50 );
	set_natural_weapon( 10, 5, 10 );
	set_natural_armor( 23, 2 );
	set_perm_stat("str",6);
	set_perm_stat("dex",4);
	set_perm_stat("con",5);
	set( "weight", 100);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
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

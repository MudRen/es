#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name("ant cooker", "�ϳ�ʦ");
	add( "id", ({ "ant" }) );
	set_short("�ϳ�ʦ");
	set_long(
	"һ������æ��׼��ʳ��ĳ�ʦ������æ��æ�������ӣ������ƺ��ܺá�\n"
	);
	set( "max_hp",100);
	set( "hit_points",100);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 20 );
	set_natural_weapon( 8, 4, 8 );
	set_natural_armor( 20, 4 );
	set_perm_stat("str",5);
	set_perm_stat("dex",5);
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

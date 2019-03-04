#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("ant keeper", "���ϰ�");
	add( "id", ({ "ant" }) );
	set_short("���ϰ�");
	set_long(
		"��Ѩ�Ƶ���ϰ壬�ʷ�׳׳�����ӣ����˿��˾��¡�\n"
	);
	set( "max_hp",140);
	set( "hit_points",140);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", -100 );
	set_natural_weapon( 13, 6, 12 );
	set_natural_armor( 28, 5 );
	set_perm_stat("str",10);
	set_perm_stat("dex",7);
	set_perm_stat("con",10);
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

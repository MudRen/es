#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("ant soldier", "սʿ��");
	add( "id", ({ "ant" }) );
	set_short("A ant solider", "սʿ��");
	set_long(
        "An exprienced ant fighter calls ant soldier .\n",
		"սʿ���Ǳȱ��Ͼ�ս���ľ��ϣ��������ͱȱ�����׳���䡣\n"
	);
	set( "max_hp",180);
	set( "hit_points",180);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 170 );
	set_natural_weapon( 20, 8, 17 );
	set_natural_armor( 38, 15 );
	set_perm_stat("str",18);
	set_perm_stat("dex",15);
	set_perm_stat("con",17);
	set( "weight", 100);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	set( "tactic_func", "call_help");
	set("alt_corpse", MOYADA"obj/ant_corpse1" );
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

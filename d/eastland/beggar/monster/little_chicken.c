#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "little chicken", "小公鸡" );
	add( "id", ({ "chicken" }) );
        set_short( "小公鸡" );
	set_long(@C_LONG
一支到处找食物的小公鸡。
C_LONG
	);
	set( "race","monster");
	set( "chicken",1);
	set( "natural_armor_class", 5 );
	set( "unit", "只" );
	set_c_verbs( ({ "%s用它的咀向%s一啄" }) );
	set_c_limbs( ({ "凤爪","鸡冠","鸡胸" }) );
        set( "tactic_func", "my_attack" );
}
int my_attack()
{
     object *env,victim;
     int i;
                
     env=all_inventory( environment(this_object()) );
     victim = query_attacker();
     if( !victim ) return 0;
                            
     for ( i=0;i<sizeof(env);i++ ) {
        if ( env[i]->query("chicken") ){
           env[i]->kill_ob( victim );
           victim->kill_ob( env[i] );
        }
     }
}

void die()
{
    object killer, big;
    
    ::die();
    killer = query("last_attacker");
    tell_room( environment(this_object()),
          "旁边一只大公鸡生气道:那里来的野孩子竟敢宰我小孩,给我去死吧!!\n");
    if( !( big=present("big chicken", environment()) ) ) {
        big = new( DMONSTER"big_chicken" );
        big->move( environment(killer) );
        big->kill_ob(killer);
    }
}    
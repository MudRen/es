#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "big chicken", "大公鸡" );
	add( "id", ({ "big","chicken"}) );
        set_short( "大公鸡" );
	set_long(@C_LONG
一只昂首阔步的大公鸡。
C_LONG
	);
        set_perm_stat("str",6);
        set_perm_stat("dex",3);
	set( "natural_armor_class", 30 );
	set( "unit", "只" );
        set( "race","monster");
	set( "chicken",1);
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
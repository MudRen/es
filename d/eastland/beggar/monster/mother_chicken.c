#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "chicken", "����" );
	add( "id", ({ "chicken"}) );
        set_short( "����" );
	set_long(@C_LONG
һֻ���ڴ���һȺС�����Ĺ�����
C_LONG
	);
        set_perm_stat("str",3);
        set_perm_stat("dex",2);
	set( "natural_armor_class", 10 );
	set( "unit", "ֻ" );
        set( "race","monster");
	set( "chicken",1);
	set_c_verbs( ({ "%s�����ľ���%sһ��" }) );
	set_c_limbs( ({ "��צ","����","����" }) );
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
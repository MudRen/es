#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "little chicken", "С����" );
	add( "id", ({ "chicken" }) );
        set_short( "С����" );
	set_long(@C_LONG
һ֧������ʳ���С������
C_LONG
	);
	set( "race","monster");
	set( "chicken",1);
	set( "natural_armor_class", 5 );
	set( "unit", "ֻ" );
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

void die()
{
    object killer, big;
    
    ::die();
    killer = query("last_attacker");
    tell_room( environment(this_object()),
          "�Ա�һֻ�󹫼�������:��������Ұ���Ӿ�������С��,����ȥ����!!\n");
    if( !( big=present("big chicken", environment()) ) ) {
        big = new( DMONSTER"big_chicken" );
        big->move( environment(killer) );
        big->kill_ob(killer);
    }
}    
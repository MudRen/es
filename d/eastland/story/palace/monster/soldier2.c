#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(17);
	set_name( "general", "������" );
	add ("id", ({"general"}) );
	set_short( "������");
	set_long(@CLONG
�����쵼����������������ڿ������춼���ţ�ȴһ���������ڵ����ӡ�
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 30 );
	set_perm_stat("int",8);
	set( "alignment", 100 );
        set( "max_fp",200);
	set_natural_weapon( 3, 6, 8 );
	set_natural_armor( 37, 15 );
        set("wealth/gold",50);
        set_skill("dodge",85);
        set_skill("parry",85);
        set_skill("shortblade",70);
        set("couple",1);
        wield_weapon(SPWEA"sword2");
        equip_armor(SPARM"soldier_shield1");
        equip_armor(SPARM"soldier_plate2");
        set("special_defense",(["all":30,"none":25]));
        set( "tactic_func", "my_attack" );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
               
int my_attack()
{
    object *couple,victim;
    int i,max;
                     
    if ( !victim = query_attacker() ) return 0;
    couple = filter_array( all_inventory(environment(this_object())),
         "can_help", this_object() );
    max=sizeof(couple);
    for( i=0; i<max; i++ ) 
       couple[i]->kill_ob(victim);
    return 0;
}
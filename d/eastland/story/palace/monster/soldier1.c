#include <mudlib.h>
#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(16);
	set_name( "soldier", "������" );
	add ("id", ({"soldier"}) );
	set_short( "������");
	set_long(@CLONG
����һλ�����춼���ŵ����������������ƺ����������ڡ�
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 24 );
        set_perm_stat("int",13);
	set( "alignment", 100 );
        set( "max_fp",200);
	set_natural_weapon( 0, 2, 14 );
	set_natural_armor( 53, 10 );
        set("wealth/gold",30);
        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("shortblade",80);
        set("couple",1);
        wield_weapon(SPWEA"sword1");
        equip_armor(SPARM"soldier_plate1");
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
    if ( !victim=query_attacker() ) return 0;                     
    couple = filter_array( all_inventory(environment(this_object())),
         "can_help", this_object() );
    max=sizeof(couple);
    for( i=0; i<max; i++ ) 
       couple[i]->kill_ob(victim);
    return 0;
}
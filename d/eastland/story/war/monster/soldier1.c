#include "../../story.h"
inherit WMOB"helpmob";
void create ()
{
	::create();
	set_level(16);
	set_name( "soldier", "������" );
	add ("id", ({"soldier"}) );
	set_short( "������");
	set_long(@CLONG
����һλ�Ƶ���������ս����ʿ��������������ɫ���ţ���Ϊ����û�в����ս����
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 24 );
        set_perm_stat("int", 23 );
	set( "alignment", 100 );
        set( "max_fp",200);
	set( "max_hp",700);
	set( "hit_points",700);
	set_natural_weapon( 10, 5, 13 );
	set_natural_armor( 53, 18 );
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
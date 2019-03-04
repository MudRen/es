#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name("jail guard","��������");
    add("id",({"guard"}) );
    set_short("��������");
    set_long(@LONG
���ǡ�н���塻�ļ������������������е����,������￴�ص��Ǻ����������
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","human");
    set("alignment",-1000);
    set_perm_stat("str",24);
    set_perm_stat("dex",23);
    set_perm_stat("kar",20);
    set_natural_armor(25,0);
    set_natural_weapon(45,20,20);
    set("hit_points",400);
    set("max_hp",400);
    set("wealth/silver",1); 
    set_skill("parry",70);
    set_skill("dodge",70);
    set("couple",1);
    wield_weapon(DWEAPON"blunt");
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
   object *couples,victim;
   int i;
      
   if( !victim=query_attacker() ) return 0;
            
   couples = filter_array( all_inventory(environment(this_object())),
            "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
       tell_room( environment(this_object()), couples[i]->query("c_name")+
             "ŭ��:�ֵ���,���һ���!!\n",couples[i]);
       couples[i]->kill_ob(victim);
   }
   return 0;
}                                                                
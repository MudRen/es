#include "../../layuter.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set("exp_reward",60000);
        set_level(19);
        set_name( "evil dragon", "��������" );
        add ("id", ({ "dragon" }) );
        set_short(" ��������");
        set("unit", "λ");
        set("alignment",-2000);
        set("weight",2000);
        set("wealth/gold",1000);
        set_long(@C_LONG
����һֻʮ��а��Ķ�������������ɱ�����������������۽����춴˴�
��������������������������������֡�
C_LONG
        );
        set_perm_stat("int", 30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar", 30);
        set_perm_stat("pie", 30);
        set_perm_stat("con", 30);
        set("max_hp",2500);
        set("hit_points",2500);
        set_natural_weapon( 95, 50, 80 );
        set_natural_armor( 100, 70 );
//	set("unbleeding",1);
        set("special_defense",
        	([ "cold" : 90, "fire" : 70, "all" : 70 , "none" : 80 ]));
        set_skill("dodge",70);
        equip_armor(Lditem"dragon_amulet");
        set("tactic_func","special_attack");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({"%s��������צ��%sץȥ","%s������ǳ��������������%sҧȥ" }));                
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}
       
       
int special_attack()
{// 20% use it! damage 40-70.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "����������β�ͣ�����������ˣ�������ˮ��û�������ܲ�ǿ�ҵس������ÿһ���ˡ�\n",
      this_object()
    );
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_damage(random(30)+40);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

void die()
{
    
    object ob1;
    
    ob1=query("last_attacker");
    announce(
"\n������½���Ͽճ��ֶ�����ƣ����������ִӿ��д��£�������콫�Ļ���\n"
"��������ݳ����ڶ�����½���Ͽգ����������������е������ƣ�\n"
"ΰ���Ӣ�� "+ob1->query("c_name")+" ������ǲ��ɲŵĵܵ���������\n"
"������Ϊ�٣���Ϊ������Ӣ��ʷд�²��õ�һҳ��\n\n");
    if ((int)ob1->query_quest_level("evil_dragon")< 1 ){
       ob1->finish_quest("evil_dragon",1);
       tell_object(ob1,"���Ѿ�������������õ� 50000�㾭��ֵ\n" );
       ob1->gain_experience(50000);    
   };
  ::die(); 
}

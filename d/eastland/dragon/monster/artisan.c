
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(15);
        set_name( "draconian artisan", "���˹���" );
        add ("id", ({ "draconian", "artisan"}) );
        set_short(" ���˹���");
        set("unit","λ");
        set("alignment",400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
���˹�������ϰ������������죬����������ϻ�û���κ�������Ʒ��
���첻�����ģ�
C_LONG
        );
        set( "inquiry", ([
         "drumstick" : "@@ask_drum",
           ]) );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",300);
        set("hit_points",300);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 11);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 40);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("shortblade",80);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
      
       
        wield_weapon(Lditem"dagger1");
        equip_armor(Lditem"boots");
}



void ask_drum( object who )
{
        tell_object( who, @ALONG
�������Ҫ���������鳣������Ҫ�ҵ�һ���������Ӳ��ľͷ������
��ԭ�е�����Ƥ��������������鳣����Կ�ȥ���������Ӳ��ľͷ��
�ɣ������ҵ�֮���������ң�����Ȼ�����ġ�
ALONG
                   );
      return ;        
}
int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_club"))!=1) return 0;
    if ((int)(ob2->query("layuter_club"))==1){
    tell_object(ob1,
         "�ü�Ȼ���Ѿ��õ��������Ӳ��ľͷ�����ҾͰ����������鳡�\n");
    tell_room(environment(this_object()),"���˹�����ʼ���ô���Ŭ��춹���\n");  
    call_out("aaa",15,this_object());
    ob3=new(Lditem"club");
    ob3->move(environment(this_object()));
       }
    else {
       tell_room(environment(this_object()),"���˹���˵��лл������\n");  
       }
          
    ob2->remove();   
   }  

void aaa(object who)
{
  tell_room(environment(who),"���˹�������������ҵĹ�������ʱ�����۵���ͷ�󺹡�\n");
   tell_room(environment(this_object()),"���˹���˵��������Ҫ�Ĺ�� ��ϣ�����ܺúõ�������\n");  
 
}

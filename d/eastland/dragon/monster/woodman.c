
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(11);
        set_name( "draconian woodman", "�����Է�" );
        add ("id", ({ "draconian", "woodman"}) );
        set_short( " �����Է�");
        set("unit","λ");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",50);
        set_long(
           "�����Է���һ���ڷܵĹ����ߡ�\n"
        );
        set_perm_stat("int", 15);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",10);
        set("max_hp",200);
        set("hit_points",200);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 20);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("axe",60);
        set_skill("parry",80);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
      
        set("chat_chance",3);
        set("chat_output",({
          "�Է�˵����!�ҵľ���ַ��ˣ�������ȳ���Ů���졣\n",
           }));
       
        dagger= new(Lditem"axe");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"chainmail");
        boots->move(this_object());
        equip_armor(boots);
}

int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_beer"))!=1) return 0;
    if ((int)(ob2->query("layuter_beer"))==1){
    tell_object(ob1,"�ǳ���л��Ϊ�Ҵ����ľƣ����Ǿ�������ҵľƳ������\n");    
    if (ob3=(present("axe",this_object()))){
      tell_object(ob1,
         "������ûʲ��ֵǮ�Ķ�����������Ѹ�ͷ�Ը����Ҷ�ʮ���ˣ������ɷ����ޱȣ��Ͱ������������͸��㡣\n"
         );        
         ob3->move(environment(this_object()));
        this_player()->set_explore("eastland#4");
       }
    ob2->remove();
    tell_room(environment(ob1), "�Է����������Ͽ�ʼ������.\n");       
   }
   
}

void die()
{  
  object ob3;
  
  
  if (ob3=(present("axe",this_object())))
    ob3->set("woodman_die",1); 
  ::die();  
    
}

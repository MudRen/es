
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(16);
        set_name( "draconian soldier", "����ʿ��" );
        add ("id", ({ "draconian", "soldier" }) );
        set_short( " ����ʿ��");
        set("unit","λ");
        set("alignment",800);
        set("weight",400);
        set("wealth/silver",500);
        set_long(
           "����ʿ���ǵ��³��ػ��ߡ�\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",20);
        set("move",1);
        set("speed",30);
        set( "patrol",({"north","north","north","south","south","west","east","south","north"}));
  
        set("max_hp",500);
        set("hit_points",500);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 8);
        set ("natural_max_damage1", 15);
        set ("natural_armor_class", 50);
        set ("special_defense",(["all":40,"none":40]));
        set ("gender", "male");
        set_skill("longblade",80);
        set_skill("parry",80);
        set_skill("block",80);
        
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
      
   
        wield_weapon(Lditem"longsword3");
        equip_armor(Lditem"plate2");
        equip_armor(Lditem"shield3");
               
}
       

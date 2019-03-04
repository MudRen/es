
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield;

        ::create();
        set_level(19);
        set_name( "draconian fighter", "����սʿ" );
        add ("id", ({ "draconian", "fighter" }) );
        set_short( " ����սʿ");
        set("unit","λ");
        set("killer",1);
        set("alignment",-400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
�������˵�ǹŴ��������ӽ������������壬������սʿ���Ǵ������о�ѡ
��������֮Ѫͳ��սʿ���������к�ǿ��ս�������ָ�����������ħ����������
������һ���µĵ��ˡ�
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set("max_fp",600);
        set("force_points",600);
        set_skill("inner_force",100);
        set("force_effect",6);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 30);
        set ("natural_armor_class", 70);
        set ("special_defense",(["all":60,"none":60]));
        set ("gender", "male");
        set_skill("longblade",100);
        set_skill("parry",100);
        set_skill("block",100);
        
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
      
        dagger= new(Lditem"longsword");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"plate");
        boots->move(this_object());
        equip_armor(boots);
        
        shield=new(Lditem"shield");
        shield->move(this_object());
        equip_armor(shield);
        
        
}

int sleet_tactic()
{

  }
       

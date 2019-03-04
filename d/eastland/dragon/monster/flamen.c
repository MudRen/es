#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object cloak;
        ::create();
        set_level(18);
        set_name( "draconian flamen budbadbump", "���˼�˾ �͵±���.�Ӳ�" );
        add ("id", ({ "draconian", "flamen","budbadbump" }) );
        set_short( " ���˼�˾ �͵±���.�Ӳ�");
        set("unit","λ");
        set("alignment",600);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
���˼�˾ �͵±���.�Ӳ���һ����ѧ��ŵ��ˣ�������\�����ص��¼��ж���
���о���������������ģ��ڹ�\���Լ��������ļ���ȶ���������ļ��⣬
ʵ��һ��ֵ�ľ��ص���������
C_LONG
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20, 10, 20);
        set_natural_armor(70, 30);
        set ("special_defense",(["all":40,"none":60]));
        set ("gender", "male");
        set_skill("shortblade",100);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
      
        cloak=new(Lditem"scroll");
        cloak->move(this_object());
        
        wield_weapon(Lditem"shortsword");
        equip_armor(Lditem"cloak");
        equip_armor(Lditem"leggings");
}

int sleet_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\nͻȻ�͵±���.�Ӳ��૵�������ص����һ���ѩ�籩����Ϯ����\n\n");
  dam=50 + random(30);
  magics->receive_special_damage("sleet",dam);
  return 1;
}

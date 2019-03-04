#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "elf elder", "���鳤��" );
        add ("id", ({ "elf", "elder" }) );
        set_short( "���鳤��" );
        set("unit","λ");
        set("alignment",600);
        set("wealth/gold",100);
        set_long(
           "���鳤������˹��һλ�Ͱ����׵ĳ��ߣ�������ǵ���ħ������ʱ\n"
           "��ħ�����ų�(yamato)��Ӣ�ۣ��ʶ��������ÿһ���Ӷ������Ļ�\n"
           "�𾴡�\n"
        );
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 45, 10, 40 );
        set_natural_armor( 60, 40 );
        set ("gender", "male");
        set ("race", "elf");
        set("tactic_func","fire_tactic");
   set("special_defense",(["all":50,"fire":35,"poison":30,"none":35]));
        set_c_verbs(({"��%ʹ�������ȷ���%s����","��%s��%s��ȥ","��%s��%s�û�"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(LWEAPON"staff");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"cloak");
        equip_armor(LARMOR"armband");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
      "\nͻȻ���鳤�����һ�����ص�����, �㿴��һƬ������Ϯ����\n\n",
       this_object() );
  dam = 65 + random(30);
  magics->receive_special_damage("fire",dam);
  return 1;
}

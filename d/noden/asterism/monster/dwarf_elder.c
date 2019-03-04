#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "dwarf elder", "���˳���" );
        add ("id", ({ "dwarf", "elder" }) );
        set_short( "dwarf elder","���˳���");
        set("unit","λ");
        set("alignment",600);
        set("wealth/gold",100);
        set_long("",
            "���˳��ϲ����Ǹ�ǿ׳��սʿҲ�Ǹ����µ�ʩ���ߡ����˱����������\n"
            "ʩ��,������ؾ����ڶ��ӵĽ��ʹ����Ҳ��ħ�����������ʶ��\n"
        );
        set_perm_stat("str", 28);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_natural_weapon( 45, 20, 30 );
        set_natural_armor( 55, 20 );
        set ("gender", "male");
        set ("race", "dwarf");
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":50,"none":10]));
        set("aim_difficulty",(["critical":100,"weakest":30,
                               "vascular":50,"ganglion":50 ])) ;
        set_skill( "blunt",100 );
        set_skill( "parry",20 );
        set_skill( "dodge",20 );
//      set_c_verbs(({"��%sʹ���޷���%s����","��%s��%s�û�"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(WEAPONS"blunt01");
        equip_armor(ARMORS"boots01");
        equip_armor(ARMORS"leggings02");
        equip_armor(ARMORS"cloak_d01");
        equip_armor(ARMORS"gloves02");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
       "���˳��ϵ����ڿ��л��˻��������Ͼ���ʼ��������ס��....\n"
       "......��ò����ײŴ��Ʊ������˳�����\n",
       this_object() );
  dam = 40 + random(20);
  magics->receive_special_damage("cold",dam);
  return 1;
}
       


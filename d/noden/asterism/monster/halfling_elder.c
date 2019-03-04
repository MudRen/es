#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "halfling elder", "�����˳���" );
        add ("id", ({ "halfling", "elder" }) );
   set_short( "�����˳���" );
        set("unit","λ");
        set("alignment",600);
        set("wealth/gold",100);
        set_long("",
            "������ῴ���������ͯ�Ƶİ����˳��ϣ���Ц����������㡣\n"
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 24);
        set_perm_stat("con",27);
        set_perm_stat("kar",26);
        set_natural_weapon( 40, 20, 33 );
        set_natural_armor( 60, 30 );
        set("aim_difficulty",(["critical":100,"weakest":20,
                               "vascular":35,"ganglion":35 ])) ;
        set ("gender", "male");
        set ("race", "halfling");
        set_skill("whip",100) ;
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":50,"none":60]));
        set_c_verbs(({"��%s����%s����","��%s��%s�û�"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(WEAPONS"long_whip");
        equip_armor(ARMORS"boots03");
        equip_armor(ARMORS"leggings02");
        equip_armor(ARMORS"cloak_h01");
        equip_armor(ARMORS"gloves02");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
       "�����˳��Ͽ��������д�....����ǰ����һ��,�㱻ӭ�������ս��ײ����\n"
       "�������ֱ��ڶ���շ��,������....��ֻ������������������ս�е�һ��....\n"
       "����ָ�֪��ȴ���ֻ�վ��ԭ��,��������Ȼ�е���շ������ʹ��\n",
       this_object() );
  dam = 35 + random(26);
  magics->receive_special_damage("mental",dam);
  return 1;
}
       


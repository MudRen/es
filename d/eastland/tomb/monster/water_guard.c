#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "water guard", "ˮ֮����" );
        add ("id", ({ "water", "guard" }) );
        set_short( "ˮ֮����");
        set("unit","λ");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"һλˮ֮�������Ǵ��ʦ�õ�����ͳ�ķ����л������ģ������������˵ص���ʥ
ʹ��\��\n"
        );
        set_perm_stat("int", 25);
        set_perm_stat("str", 23);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 42, 12, 39 );
        set_natural_armor( 78, 11 );
        set ("gender", "male");
        set ("race", "daemon");
        set("tactic_func","water_tactic");
        set("special_defense",(["cold":30,"none":30,"fire":-20]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        equip_armor(ARMORS"/water_ring");
        equip_armor(ARMORS"/water_amulet");
}

int water_tactic()
{
  object victim;
  int dam;
  
 if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"ˮ֮�����������Ļ���������˻ӣ���ͻȻ����һ����!!\n",
       this_object() );
  dam = 50 + random(25);
  victim->receive_special_damage("cold",dam);
  return 1;
}

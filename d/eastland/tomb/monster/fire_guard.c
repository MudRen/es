#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "fire guard", "��֮����" );
        add ("id", ({ "fire", "guard" }) );
        set_short( "��֮����");
        set("unit","λ");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"һλ��֮�������Ǵ��ʦ�õ�����ͳ�ķ����л������ģ������������˵ص���ʥ
ʹ��\��\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 40, 15, 38 );
        set_natural_armor( 75, 13 );
        set ("gender", "male");
        set ("race", "daemon");
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":30,"none":30,"fire":50]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        equip_armor(ARMORS"/fire_leggings");
        equip_armor(ARMORS"/fire_amulet");
}

int fire_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"��֮����ͻȻ��˫�ְ��ڻ����ϣ������һ�Ż�������ײ�� !!\n",
       this_object() );
  dam = 45 + random(25);
  victim->receive_special_damage("fire",dam);
  return 1;
}

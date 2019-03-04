#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "wind guard", "��֮����" );
        add ("id", ({ "wind", "guard" }) );
        set_short( "��֮����");
        set("unit","λ");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"һλ��֮�������Ǵ��ʦ�õ�����ͳ�ķ����л������ģ������������˵ص���ʥ
ʹ��\��\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",20);
        set_natural_weapon( 46, 14, 36 );
        set_natural_armor( 77, 14 );
        set("skills",(["dodge":80]) );
        set("gender", "female");
        set("race", "daemon");
        set("tactic_func","wind_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        equip_armor(ARMORS"/wind_boots");
        equip_armor(ARMORS"/wind_amulet");
}

int wind_tactic()
{
  object ob1,ob2;
  int times,heal;
  
  ob1=this_object();
  
  if ( !(ob2=query_attacker()) || (random(10)>2)) return 0;
  
  tell_room(environment(),
       "\n"+"��֮������˫�־���ͻȻһ������Χ���� !!\n",
       this_object() );
  heal = 45 + random(25);
  ob1->receive_healing(heal);
  return 1;
}

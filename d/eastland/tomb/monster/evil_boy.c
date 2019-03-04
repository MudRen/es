#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "evil boy", "С��ͯ" );
        add ("id", ({ "evil", "boy" }) );
        set_short( "С��ͯ");
        set("unit","λ");
        set("alignment",-2000);
        set("wealth/gold",200);
        set_long("",
"һλ�ɰ���Сͯ�ӣ����Ǵ��ʦ�����̶�֮ͯһ����˵���Ǵ��ʦ��һ����ս������
���ģ���Ϊ�м����ʦ�Ķ���ɱ֮������Ǳ���ڴ��ʦ�����ԣ�����Ϊһͯ������
�̴��ʦ��\n"
        );
        set_perm_stat("int", 19);
        set_perm_stat("dex", 22);
        set_perm_stat("kar", 17);
        set_perm_stat("str", 25);
        set( "max_hp",500 );
        set( "hit_points", 500);
        set_natural_weapon( 40, 15, 35 );
        set_natural_armor( 80, 25 );
        set("skills",(["dodge":85,"block":85,"dagger":85]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","evil_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(WEAPONS"/evil_dagger");
        equip_armor(ARMORS"/black_du_do");
}

int evil_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"��ͯ�ӿ��������дʣ�ͻȻ����˫�۱������⣬����Ϯ��!!\n",
       this_object() );
  dam = 45 + random(25);
  victim->receive_special_damage("evil",dam);
  return 1;
}

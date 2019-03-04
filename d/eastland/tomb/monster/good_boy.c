#include "../almuhara.h"
 
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(17);
        set_name( "good boy", "С��ͯ" );
        add ("id", ({ "good", "boy" }) );
        set_short( "С��ͯ");
        set("unit","λ");
        set("alignment",2000);
        set("wealth/gold",200);
        set_long(
"һλ�ɰ���Сͯ�ӣ����Ǵ��ʦ�����̶�֮ͯһ����˵���Ǵ��ʦ������ħ����ս��
�����񵽵Ĺ¶���ȴ��Ϊ����а���ħ�������ܼ�����������Ǳ���ڴ��ʦ����
�ԣ����ʦ����������ʦ�ุ�Ĺ�ϵ��\n"
        );
        set_perm_stat("int", 23);
        set_perm_stat("dex", 23);
        set_perm_stat("kar", 20);
        set_perm_stat("str", 22);
        set( "max_hp",700 );
        set( "hit_points", 700);
        set_natural_weapon( 45, 10, 30 );
        set_natural_armor( 85, 20 );
        set("skills",(["dodge":85,"parry":85,"shortblade":85]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","divine_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(WEAPONS"/sunsword");
        equip_armor(ARMORS"/white_du_do");
        set( "inquiry", ([
"seal" : ({  "ร������������ʦ˵�����������ѽ����Ƴ���ӡ�Ĺؼ������Ǻ������\n"
	     "����(insert)�Ǵ�ʯ�С�\n"
	     "\n"
	     "�....��ʦ��˵��ʲ�ᡸ�����֡�������������������....�ǲ�����..:P\n"
	     "��֣��㲻��ȥ���Ҽ������....�� !! \n" })
		]) );     
}
 
int divine_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"��ͯ�ӿ��������дʣ�ͻȻ����˫�ֱ�þ޴��ޱȣ�����ѹ��!!\n",
       this_object() );
  dam = 30 + random(20);
  victim->receive_special_damage("divine",dam);
  return 1;
}

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;
#include "../magic.c"

void create()
{
  ::create();
  set_level(17);
  set_name("poisonous moth", "�����");
  add( "id", ({ "moth" }) );
  set_short("�����");
  set_long(@LONG
�ţ���һ�ſֲ��Ĺ�������ϸһ�ƣ����ǲ����ˣ���Ȼ���׶�Ĺ���ꡣ��˵
���ֶ�����ϲ����ʳ���ж������֭������Ҳ�������֮һ���������µ���
�۶��Ǿ綾�����ҹ����Լ�ǿ����ʹ����Ҫ��ʳ��Ҳ������Ķ�ɱ�������
LONG
    );
  set( "race", "insect" );
  set( "unit", "ֻ" );
  set( "alignment", -1000 );
  set_natural_armor( 10, 10 );
  set( "max_hp", 500 );
  set( "hit_points", 500 );
  set_skill("dodge",100);
  set_perm_stat( "str", 22 );
  set_perm_stat( "int", 22 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 30 );
  set_natural_weapon(50,20,25);
  set("aim_difficulty",(["critical":80,"vascular":70,"ganglion":100]));
  set("special_defense",(["all":60,"none":40]));
  set( "killer", 1 );
  set( "time_to_heal", 20 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "���", "����" }) );
  set_c_verbs( ({ "%s��%sɢ���������׷�" ,
                  "%s�ó�����%s"
                  }) );
}

int emit_poison()
{
  object victim;
  int i;

  if( random(20)>8 || !(victim= query_attacker()) ) return 0;
  if ((i=random(16))>10) {
    tell_object( environment(this_object()),
      "�㲻С�����������ɢ�µĶ��ף�������ģ��......\n"
      );
    (CONDITION_PREFIX + "confused")->apply_effect( victim, 7, 25 );
    victim->receive_special_damage("poison",40); 
    report(this_object(),victim);
    return 1;
  }
  else if (i>5) {
    tell_object( environment(this_object()),
      "�����ӳ�һ���׷ۣ���һ��ʧ����֫�������׷ۣ��ֽ�һ�����.....\n"
      ); 
    (CONDITION_PREFIX + "slow")->apply_effect(victim,20,10 );
    victim->receive_special_damage("poison",40); 
    report(this_object(),victim); 
    return 1;  
  }
  else {
    tell_object( environment(this_object()),
      "����궣����һ��.....\n"
      );
    (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,7,25 );
    victim->receive_special_damage("poison",25);
    report(this_object(),victim);
    return 1;
  }
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",4);
     ::die();
}
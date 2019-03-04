#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"

inherit MONSTER;

void create()
{
  ::create();
  set_level(18);
  set_name("crystal leech", "��ˮ���");
  add( "id", ({ "leech" }) );
  set_short("��ˮ���");
  set_long(@LONG
һ����Ѫˮ�Σ���Ϊͨ��͸��������ͬ���֮ˮһ�㣬�����˳���ˮ��ȡ�ÿ
������ʳ��������ѪҺ��ʱ������͸������Һ����Ѫ����һ�𣬻�����õ
��ʯ�������ɫ��ʮ�ֺÿ���
LONG
    );
  set( "race", "amphibia" );
  set( "unit", "ֻ" ); 
  set( "alignment", -800 );
  set_natural_armor( 10, 20 );
  set( "max_hp", 600 );
  set( "hit_points", 600 );
  set_skill("dodge",100);
  set_perm_stat( "int", 20 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 30 );
  set_natural_weapon(60,30,50);
  set("aim_difficulty",(["critical":90,"ganglion":50]));
  set("special_defense",(["all":40,"none":20]));
  set( "killer", 1 );
  set( "time_to_heal", 40 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
  set_c_verbs( ({ "%s�ݺݵ�ҧס%s��Ƥ������ʼ��Ѫ" ,
                  "%s�ø�����������ݻ�����%s��Ƥ��"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>8 || !(victim= query_attacker()) ) return 0;   
  if (random(5)>2) { 
    tell_object( victim,
      "\n��Ƚ�����ҧס����ֱۣ�ֻ����ȵ���ɫ��͸��תΪ�ۺ죬�����쳣....\n\n"
      );
    victim->receive_damage(30);
    this_object()->receive_healing(30);  
    report(this_object(),victim);
    return 1;
  }
tell_object(victim,
  "��Ĵ�����Ϊ�����ҧ��һ�ڶ������......\n");
  victim->block_attack(2);
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",4);
     ::die();
}
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(10);
  set_name("poisonous mosquito", "���߶���");
  add( "id", ({ "mosquito" }) );
  set_short("���߶���");
  set_long(
    "���ƴ�ĺں�ɫ���ã������м�����ɫ�ߵ㣬��~~~~����������˹�����\n"
    );
  set( "race", "insect" );
  set( "unit", "ֻ" );
  set( "exp_reward", 1200 );
  set( "alignment", -500 );
  set_natural_armor( 45, 10 );
  set_natural_weapon( 30,10,15);
  set( "max_hp", 200 );
  set( "hit_points", 200 );
  set_perm_stat( "int", 2 );
  set_perm_stat( "dex", 30 );
  set( "killer", 1 );
  set( "time_to_heal", 5 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "���", "����" }) );
  set_c_verbs( ({ "%s��������~~���������%s" ,
                  "%s�ü���Ŀ�������%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object( environment(this_object()),
    "���ó��㲻ע���ʱ��͵������һ��......\n"
    );
  (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 15 );
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",1);
     ::die();
}
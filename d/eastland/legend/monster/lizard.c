#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(13);
  set_name("huge lizard", "ʳ������");
  add( "id", ({ "lizard" }) );
  set_short("ʳ������");
  set_long(
    "һֻ�޴�����棬�������¶���һ���ɫ��Һ�帲������\n"
    );
  set( "race", "amphibia" );
  set("killer",1);
  set( "unit", "ֻ" );
  set( "exp_reward", 1500 );
  set( "alignment", -800 );
  set_natural_weapon(40,20,20);
  set_natural_armor( 45, 10 );
  set( "max_hp", 300 );
  set( "hit_points", 300 );
  set( "aim_difficulty",(["ganglion":70]));
  set_perm_stat( "int", 1 );
  set_perm_stat( "str",40 );
  set_perm_stat( "dex", 15 );
  set_perm_stat( "str", 25 );
  set( "aggressive", 1 );
  set( "time_to_heal", 10 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "ǰ��", "���" }) );
  set_c_verbs( ({ "%s�������ɫ����ͷ������%s" ,
                  "%s������β��ת��ɨ��%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object( environment(this_object()),@LONG
��ݺݵĻ�����ʳ�������β�ͣ� ����һ���ȳ��İ���ɫҺ��ȴ��
������˿����˳������������������......
LONG
    );
  (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 10 );
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",2);
     ::die();
}
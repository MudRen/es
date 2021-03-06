#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(10);
  set_name("poisonous mosquito", "花斑毒蚊");
  add( "id", ({ "mosquito" }) );
  set_short("花斑毒蚊");
  set_long(
    "巴掌大的黑褐色毒蚊，腹部有几处黄色斑点，嗡~~~~的正朝你飞了过来。\n"
    );
  set( "race", "insect" );
  set( "unit", "只" );
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
  set_c_limbs( ({ "头部", "身体", "翅膀", "腹部" }) );
  set_c_verbs( ({ "%s发出嗡嗡~~的声响冲向%s" ,
                  "%s用尖锐的口器叮向%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object( environment(this_object()),
    "毒蚊趁你不注意的时候偷叮了你一口......\n"
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
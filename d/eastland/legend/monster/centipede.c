#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"

inherit MONSTER;

void create()
{
  ::create();
  set_level(16);
  set_name("flower centipede", "五彩斑斓的巨型花蜈蚣");
  add( "id", ({ "centipede" }) );
  set_short("五彩斑斓的巨型花蜈蚣");
  set_long(@LONG
一只馀两丈长的巨型蜈蚣。要不是有如钢铁般的百足，简直跟一条巨蟒没有两样。
五彩斑斓的甲壳，十三个透明的眼珠，口中还咬著一只山猪，山猪全身泛黑，而且
表皮已成半透明状，想来这只蜈蚣必有剧毒。
LONG
    );
  set( "race", "insect" );
  set( "unit", "只" );
  set( "alignment", -1200 );
  set_natural_armor( 40, 10 );
  set( "max_hp", 300 );
  set( "hit_points", 300 );
  set_skill("dodge",100);
  set_perm_stat( "str", 22 );
  set_perm_stat( "int", 20 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 27 );
  set_natural_weapon(50,25,25);
  set("aim_difficulty",(["critical":90,"weakest":50,"ganglion":100]));
  set("special_defense",(["all":30,"none":20]));
  set( "killer", 1 );
  set( "time_to_heal", 20 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "头部", "身体", "百足", "尾部" }) );
  set_c_verbs( ({ "%s对%s喷出一口黑气" ,
                  "%s的尾巴一卷，卷住了%s",
                  "%s用锐利的口喙咬向%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>10 || !(victim= query_attacker()) ) return 0;
  tell_object( victim,sprintf(
    "\n哎呀！糟糕！你被花蜈蚣所吐的%s喷中了......\n",set_color("黑气","CYN"))
    );
  (CONDITION_PREFIX + "simple_poison")->apply_effect( victim,5, 20 );
  victim->receive_special_damage("poison",30);  
  report(this_object(),victim);
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",3);
     ::die();
}
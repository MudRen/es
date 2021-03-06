#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "fire guard", "火之护卫" );
        add ("id", ({ "fire", "guard" }) );
        set_short( "火之护卫");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位火之护卫，是大国师用道家正统心法所招唤出来的，他负有守卫此地的神圣
使命\。\n"
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
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        equip_armor(ARMORS"/fire_leggings");
        equip_armor(ARMORS"/fire_amulet");
}

int fire_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"火之护卫突然将双手按在护符上，变成了一团火焰向你撞来 !!\n",
       this_object() );
  dam = 45 + random(25);
  victim->receive_special_damage("fire",dam);
  return 1;
}

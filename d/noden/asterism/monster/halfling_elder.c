#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "halfling elder", "半身人长老" );
        add ("id", ({ "halfling", "elder" }) );
   set_short( "半身人长老" );
        set("unit","位");
        set("alignment",600);
        set("wealth/gold",100);
        set_long("",
            "这个怎麽看都像个老顽童似的半身人长老，正笑咪咪的望著你。\n"
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 24);
        set_perm_stat("con",27);
        set_perm_stat("kar",26);
        set_natural_weapon( 40, 20, 33 );
        set_natural_armor( 60, 30 );
        set("aim_difficulty",(["critical":100,"weakest":20,
                               "vascular":35,"ganglion":35 ])) ;
        set ("gender", "male");
        set ("race", "halfling");
        set_skill("whip",100) ;
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":50,"none":60]));
        set_c_verbs(({"用%s挥向%s攻击","用%s向%s敲击"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(WEAPONS"long_whip");
        equip_armor(ARMORS"boots03");
        equip_armor(ARMORS"leggings02");
        equip_armor(ARMORS"cloak_h01");
        equip_armor(ARMORS"gloves02");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
       "半身人长老口中念念有词....你眼前景物一晃,你被迎面而来的战车撞倒。\n"
       "紧接著又被第二辆辗过,第三辆....你只能躺著无助地望著混战中的一切....\n"
       "等你恢复知觉却发现还站在原处,但身上依然感到被辗过的疼痛。\n",
       this_object() );
  dam = 35 + random(26);
  magics->receive_special_damage("mental",dam);
  return 1;
}
       


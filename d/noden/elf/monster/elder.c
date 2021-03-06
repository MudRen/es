#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "elf elder", "精灵长老" );
        add ("id", ({ "elf", "elder" }) );
        set_short( "精灵长老" );
        set("unit","位");
        set("alignment",600);
        set("wealth/gold",100);
        set_long(
           "精灵长老乔纳斯是一位和蔼可亲的长者，由於他是当年魔族入侵时\n"
           "打倒魔王军团长(yamato)的英雄，故而精灵族的每一份子都对其心怀\n"
           "尊敬。\n"
        );
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 45, 10, 40 );
        set_natural_armor( 60, 40 );
        set ("gender", "male");
        set ("race", "elf");
        set("tactic_func","fire_tactic");
   set("special_defense",(["all":50,"fire":35,"poison":30,"none":35]));
        set_c_verbs(({"用%使出精灵杖法向%s攻击","用%s向%s刺去","用%s向%s敲击"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(LWEAPON"staff");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"cloak");
        equip_armor(LARMOR"armband");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
      "\n突然精灵长老念出一串神秘的咒语, 你看见一片火海向你袭来。\n\n",
       this_object() );
  dam = 65 + random(30);
  magics->receive_special_damage("fire",dam);
  return 1;
}

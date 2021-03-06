#include "../oldcat.h"

inherit MONSTER;

void create ()
{
    ::create();
    set_level(16);
    set_name("the wizard Corak","矮灵巫师科拉克");
    add("id",({"wizard","corak"}) );
    set_short("矮灵巫师科拉克");
	set_long(
@LONG
一个矮灵巫师，科拉克是矮灵族历史上最强的巫师，他负责向火神乞求每年的平静。
LONG
	);
    set("alignment",-880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",18);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("wealth", ([ "gold":30]) );
    set ("max_hp", 500);
    set ("hit_points", 500);
    set ("aim_difficulty", ([ "critical":50,"weakest":30,"vascular":30 ]) );
    set_natural_armor( 36 ,15 );
    set_natural_weapon(2,7,15);
    set ("weight", 350);
    set_skill("shortblade",90);
    set("special_defense", (["all":33,"none":20]) ); 
    set( "tactic_func", "cast_spell");
    set("chat_chance",5);
    set("chat_output", ({
        "\n巫师说：我们明年的祭品还没有著落，你愿意牺牲自己吗 ?\n\n",
        "\n巫师说：还好今年的祭品已经有著落了，又可以平安的度过一年。\n\n"
    }) );
    set("inquiry",([
        "volcano":"@@ask_volcano",
        ]) );
    wield_weapon(OWEAPON"shortsword1");
    equip_armor(OARMOR"mail1");
    equip_armor(OARMOR"ring1");
}

void ask_volcano(object who)
{
  tell_object(who,
    "巫师说：只要我们每年在这里血祭一位活人，火神就不会发怒，火山就不会爆发。\n"
  );
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()),
        "\n\n科拉克念了一段咒语：FENDI MENTAR DIVI CREMBI MENTAR BONI\n"
        "空中出现一道青色的闪光直击向科拉克的敌人，并且给与敌人致命的攻击。\n\n"
         );
      victim->receive_special_damage("fire", 20+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()),
        "科拉克呼唤矮灵的守护神医疗他自己。\n"
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}

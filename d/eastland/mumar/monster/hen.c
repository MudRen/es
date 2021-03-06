#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        object mark;
        ::create();
        set_level(16);
        set_name( "General hen", "牙将 哼将军" );
        add ("id", ({ "general", "hen", }) );
        set_short( "牙将 哼将军" );
        set_long(
    "牧马关的两位副将之一，哼将军，他全身散发出一阵寒气。\n"
    "哼将军现任牧马关骑兵团总指挥，所有骑兵和马匹的调度，都是由他负责。\n");
 
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
    set_perm_stat( "str", 20 );
    set_perm_stat( "dex", 15 );
    set_perm_stat( "int", 10 );
    set ("wealth", ([ "gold": 30 ]) );
    set_natural_weapon(10,10,20);
    set_natural_armor(72,35);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 5);
    set("chat_output",({
        "哼将军对你「哼」的一声。\n",
        "哼将军忽然打个喷嚏～，对你说道：「好冷～！」\n",
        "哼将军全身气孔散发著寒气，冷笑地看著你。\n"
        }));
    set_skill("longblade",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
    set("tactic_func","cold_tactic");
    wield_weapon(OBJS"shining_blade");
    equip_armor(OBJS"cloak02");
    equip_armor(OBJS"shield02");
 
    mark=new(OBJS"mark_c");
    mark->move(this_object());
}
 
int cold_tactic()
{
  object vvv;
  int dam;
 
  if ( !(vvv=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然，哼将军全身骨骼暴响，一道逼人的寒气藉著剑划向敌人。\n\n");
  dam=20 + random(10);
  vvv->receive_special_damage("sleet",dam);
  return 1;
}

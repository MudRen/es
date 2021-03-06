#include "../iigima.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name("eight tail snake","八歧大蛇 ");
        add( "id", ({ "snake" }) );
        set_short("snake","八歧大蛇 ");
        set_long(@C_LONG
天呐？！这是个什麽样的怪物？一条有八条尾巴的巨蛇，你几乎不相信，这会是
存在於这个世界上的生物！火红的眼睛闪烁著燃烧异样的光芒，一身黑褐色的鳞
甲，尤其是那八条蠕动的尾巴，不时地发出吱吱的声音，更是看了胆颤心惊！！
C_LONG
        );
        set( "unit", "条" );
        set( "alignment", -1000 );
        set_perm_stat( "dex", 24 );
        set_perm_stat( "str", 22 );
        set("max_hp",600);
        set("hit_points",600);
        set( "weight", 3000 );
        set( "special_defense", ([ "all":20,"evil":80,"fire":50,"none":5]) );
        set( "aim_difficulty", ([
            "ganglion" :10, "weakest" :20, "vascular" :10 ]) );
        set_natural_armor( 75, 20 );
        set( "natural_weapon_class1", 29 );
        set( "natural_min_damage1", 35 );
        set( "natural_max_damage1", 45 );
        set_skill( "dodge",90 );
        set_c_limbs( ({ "头部", "庞大身躯", "尾巴" }) );
        set_c_verbs( ({
                       "%s昂头张开大嘴，朝%s咬过去！",
                       "%s甩动它的头，向%s撞了过去！",
              }));
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "八岐大蛇发出吱吱的叫声！\n",
                "八岐大蛇用血红的眼睛瞪著你！\n",
                "八歧大蛇围绕在阵阵的黄色烟雾当中...\n",
                        }));
        set("tactic_func","special_attack");
        set( "killer", 1 );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);

  if (random(22)<7) {
    tell_room(environment(this_object()),
"八岐大蛇发出刺耳的尖叫，疯狂甩动八条尾巴，形成一股漩涡气流，横扫千军\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);
    return 1;
  }
  if (random(25)<7) {
    tell_room(environment(this_object()),
"八岐大蛇张开血盆大口，突然激射出千万利牙刺向所有人！\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  if (random(33)<7) {
    tell_room(environment(this_object()),
"八岐大蛇的火红双眼怒视四方，八条尾巴卷起有如死神降临人间，狂暴冲击攻向在场
所有敌人！！\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+20);
    return 1;
  }
}
void announce( string c_msg )
{
        object *usr;
        int i;
        usr = users();
        for( i=0; i<sizeof(usr); i++ ) {
                if( !environment(usr[i]) ) continue;
                tell_object( usr[i], c_msg);
        }
}
void die()
{
        object obj;
        obj = query("last_attacker");
        if (obj->query_temp("drow_certi") != 3)
        {
	tell_room(environment(obj),
		"大蛇狂吼一声，倒在地上，死了。",this_object() );
	::die(1);
        }

        announce(
        "诺顿皇宫的地底下不断传来阵阵的尖叫声....\n"
        "整个诺顿皇城不断的震动著!!\n");
        if( (int)obj->query_quest_level("drow_disaster") < 1 )
        {
        obj->finish_quest("drow_disaster",1);
        tell_object( obj, "你已经完成这个任务, 你得到10000点经验值。\n" );
        obj->gain_experience(10000);
        }
        ::die(1);
}


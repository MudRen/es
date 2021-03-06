
#include "../moyada.h"

inherit TEACHER;
inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(18);
	set_name( "Grey", "葛雷" );
	add ("id", ({ "grey", "adventurer", }) );
	set_short( "旅游冒险家 葛雷" );
	set_long( @LONG
    到世界各地寻找财宝的旅行冒险家, 有著灰色的头发和碧篮色的眼睛。
因为到过世界各地旅行, 而锻练出傲人的肌肉和体魄, 看起来颇为自负。
LONG
	);
	set( "alignment", 1000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "pursuing" ,1);
    set( "unit", "个" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 9 );
	set_perm_stat( "karma", 21 );
	set("max_hp", 950);
	set("hit_points", 950);
	set("wealth", ([ "gold": 50 ]) );
	set_natural_weapon( 35, 15, 35 );
	set_natural_armor( 35, 30 );
    set("weight", 800);
    set("exp_reward",19000 );
    set_experience(450000);
    set_skill("parry",80);
    set_skill("block",60);
    set_skill("dodge",85);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
    wield_weapon( MOYADA"obj/grey_sword" );
    equip_armor( MOYADA"obj/snake_plate" );
    equip_armor( MOYADA"obj/dragon_shield" );
   set( "chat_chance", 12 );
   set( "chat_output", ({
         "葛雷叹道: 都没有学生可以教, 真无聊!\n" }) );
    set( "inquiry", ([
            "help" : "@@ask_help",
            "train" : "你想学如何用盾牌抵挡敌人的攻击吗?\n" ]) );
    set("tactic_func", "special_attack"); 
    set_lessons( ([
                "block" : ({ 200, 50 })
    ]) );
}

void init()
{
   npc::init();
   teacher::init();
}

void ask_help( object who )
{
    tell_object( who, 
      "葛雷说: 你来的正好, 这家店的老板好像正想用人, \n"
      "        你可以问他看看还有没有(job)。\n" 
    );
}

// 10% use it! damage 40-50.
int special_attack()
{
    object *victim;
	        int i;
    
    if( !(victim = query_attackers()) || (random(10)>1) ) return 0;
    tell_room( environment( this_object() ), 
      "\n葛雷大喊: 看我的绝招 真空斩! \n"+
      "  只见葛雷举剑一劈，无数条弯月型的光波向所有敌人射去。\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+40);
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}

int check_trainee(object who)
{
    if( (string)who->query("class")=="adventurer" &&
        (int)who->query_level()>4 )
    return 1;
    else return notify_fail(
      "葛雷说: 我只教够资格的冒险者。\n" );
}


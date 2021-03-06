#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Emperor Yuishu","遥照");
    add("id",({"emperor","yuishu"}) );
    set_short("遥照天皇");
    set_long(@C_LONG
遥照天皇虽然年纪一大把了，可是却还很有精神；只见他拿了把木刀，缓缓
的挥舞著，姿势十分的优雅。咦～～！仔细一看，这刀法还真颇有大家风范
，只见他身形步伐均十分灵巧，攻守有度，一股王者的风范拢罩著他的全身
，你的直觉告诉你：他是位不平凡的人物。
C_LONG
            );
    set("unit","位");
    set("gender","male");
    set("race","daemon");
    set("alignment",-2000);
    set("class","scholar");
    set("time_to_heal",10);
    set_natural_armor(85,30);
    set_natural_weapon(80,30,45);
    set_perm_stat("str",25);
    set_perm_stat("dex",30);
    set_perm_stat("int",30);
    set_perm_stat("kar",30);
    set("max_hp",800);
    set("hit_points",800);
    set("max_fp",1000);
    set("force_points",1000);

    set("attack_skill",CLASS"han");
    set("scholar_gonfu/han",30);
    set("scholar_gonfu/poem",30);
    set("scholar_gonfu/song",30);
    set("scholar_gonfu/tang",30);
    
    set_skill("parry",100);
    set_skill("tactic",100);
    set("tactic","flank");
    set("wealth/gold",500);
    set("aim_difficulty",(["critical":100,"vascular":100,"ganglion":20,
    "weakest":0]) );
    set("special_defense",(["evil":20,"fire":60,"cold":60,"energy":70,
                            "electric":80,"none":40]) );
    set("exp_reward",37000);
    set("tactic_func","my_tactic");
    set("chat_chance",20);
    set("att_chat_output",({"\n遥照大喝：小子，这就是「汉赋剑法」，眼睛睁大了！\n\n"}) );
    call_out("myskill01",25);
    
    wield_weapon(TWEP"sword2");
    equip_armor(TOBJ"cloth2");
    equip_armor(TOBJ"skirt2");
    equip_armor(TOBJ"feet2");
    equip_armor(TOBJ"ring1");
    equip_armor(TOBJ"amulet1");
}

void myskill01()
{ 
  delete("att_chat_output");
  set("att_chat_output",({"\n遥照神形一转，「古诗剑法」一招一招递将过来！\n\n"}));
  delete("attack_skill");
  set("attack_skill",CLASS"poem");
      call_out("myskill02",25);
 } 
 void myskill02()
 {
   delete("att_chat_output");
   set("att_chat_output",({"\n遥照奸笑著：见识见识一下「宋词剑法」吧！\n\n"}));
   delete("attack_skill");
   set("attack_skill",CLASS"song");
   call_out("myskill03",25);
}
void myskill03()
{ 
    delete("att_chat_output");
    set("att_chat_output",({"\n遥照突然恭谨的说：让我用「唐诗剑法」来招待阁下的躯体吧！\n\n"}));
    delete("attack_skill");
    set("attack_skill",CLASS"tang");
    call_out("myskill04",25);
}    

void myskill04()
{
    delete("att_chat_output");
    set("att_chat_output",({"\n遥照大喝：小子，这就是「汉赋剑法」，眼睛睁大了！\n\n"})); 
    delete("attack_skill"); 
    set("attack_skill",CLASS"han");  
    call_out("myskill01",25);
}  

int my_tactic()
{
    object *victim;
    int i;
    
    if( (int)this_object()->query("hit_points") >= 80 )return 0;
    if( random(100)>5 || !victim = query_attackers() ) return 0;
    
    tell_room( environment(this_object()),
        "\n遥照大喝：秘～技，树～雷～升～龙～霸!!一股强劲将所有人给送上天去了..\n\n");
       for( i=sizeof(victim)-1; i>=0; i--){
        victim[i]->receive_special_damage("evil",30);
        report(this_object(),victim[i]);
        victim[i]->move_player(CITY"star_room",
        "你看到他越飞越高，瞬间一闪，就变成天上的星星了!"
        , "天上的星星突然又一闪，哇，变成流星坠下来了!"); 
        }
    call_out("call_back",30,victim);
    return 1;
} 

int call_back(object *victim)
{
    int i;
    
    for( i = sizeof(victim)-1; i >= 0; i--){
    tell_object( victim[i],
        "\n当你正沈醉於灿烂的星河中时，一股吸力逐渐将你拉回地面上....\n\n");
        victim[i]->move_player(CITY"garden2");
        }
    return 1;
}
void die()
{
    object *victim;
    victim=all_inventory(find_object_or_load(CITY"star_room"));
    call_back(victim);
    ::die();
    return;
}           


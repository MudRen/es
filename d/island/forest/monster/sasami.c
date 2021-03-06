#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "Princess Sasami", "砂纱美" );
    add( "id",({"sasami","princess"}) );
    set_short( "砂纱美公主");
    set_long(@LONG
砂纱美是树雷王家的第二公主。她是个非常可爱的小女孩，和她那任性的姊姊
完全不同。传说她具有与船穗沟通的能力，所以，你千万不要小看她哦；魉皇鬼是
砂纱美的宠物，可是不知道跑到哪儿去了，如果你答应帮她找回来的话，她会告诉
你有关魉皇鬼(luoky)的详细情形的！
LONG
            );
    set("unit","位");
    set("race","daemon");      
    set("class","healer");
    set("age",10);
    set("gender","female" );
    set("alignment",800);
    set("weight",300);
    set("wealth/gold",150);
    set_perm_stat("str",18);
    set_perm_stat("dex",15);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set_perm_stat("pie",30);
    set("time_to_heal",30);
    set("hit_points",500);
    set("max_hp",500);
    set("spell_points",200);
    set("max_sp",200);
    set_natural_armor(55,27);
    set_natural_weapon(45,0,15);
    set_skill("dagger",70);
    set_skill("anatomlogy",90);
    set_skill("dodge",70);
    set_skill("block",80);
    set_skill("tactic",80);
    set("tactic","assault");
    set("special_defense",(["evil":60,"energy":0,"fire":50,"cold":50,
                            "electric":50,"none":20]) );
    set("aim_difficulty",
    (["critical":-20,"vascular":80,"ganglion":20,"weakest":80]) );
    set("aiming_loc","weakest");

    set("inquiry",([
        "luoky":"@@ask_luoky"]) );
    set("exp_reward",20000);
        
    wield_weapon(TWEP"key2");
    equip_armor(TOBJ"shield1");
    equip_armor(TOBJ"arms");
    equip_armor(TOBJ"leggings");
}

int accept_item(object player,object ob)
{
    if( !ob || !(ob->query("give_to_sasami")) ) return 0;
    if( (string)ob->query("winner") != (string)player->query("name") ){
      tell_room(environment(),
"纱砂美有点失望的说：谢谢你把它送回来，但还是请你帮我对那位好心人士说声谢谢！\n"
"纱砂美公主把心爱的宠物关回笼中！\n");
      return 1;
      }  
    if( (int)player->query_quest_level("find_luoky") < 1) {
    tell_object(player,"谢谢你为我找回魉皇鬼，谢谢！\n");
    tell_room(environment(),
       "砂纱美公主把心爱的宠物关回笼中！\n");
       player->finish_quest("find_luoky",1);
    tell_object(player,
      "你已经完成了这个任务，你得到1000点经验值\n");
       player->gain_experience(1000);
       ob->remove();
       return 1;
     }
     tell_object(player,"再次感谢您的帮忙！谢谢！！\n");
     tell_room(environment(player),
       "砂纱美以微笑对"+player->query("c_name")+"的热心表示感谢！！\n"); 
     return 1;
 } 
 
 void ask_luoky()
 {
    write(@ALONG
魉皇鬼吗？它是我心爱的宠物，长得有点像小兔子，两只耳朵长长的，叫声很像
猫；我昨天带它到院子去玩的时候，它突然就走失了，你愿意帮我把它找回来吗？
啊？我忘了告诉你，要抱它的话，一定要拿萝卜给它才能抱哦，不然他会咬你哦！
谢谢你！！^_^
ALONG
        );
	return ;
}
void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}        

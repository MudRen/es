#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(18);
    set_name( "Princess Aiga", "阿重霞" );
    add( "id",({"aiga","princess"}) );
    set_short( "阿重霞公主");
    set_long(@C_LONG
阿重霞是树雷王家的第一公主。发现你在偷看，於是对你深情一笑．．．！虽然她
长得十分可爱，但却十分任性。千万不要惹她生气哦，她生气起来可是很可怕的，你
可别被她的外表迷惑了哦！她不知为何，脸上带有一丝丝的忧郁，到底是什麽事情令
她如此哀伤(sadness)呢？
C_LONG
            );
    set("gender","female");
    set("unit","位");
    set("class","scholar");
    set("race","daemon");
    set("age",18);
    set_perm_stat("str",21);
    set_perm_stat("dex",16);
    set("alignment",1000);
    set("weight",400);
    set("wealth/gold",200);
    set("hit_points",550);
    set("max_hp",550);
    set("special_defense",(["evil":55,"fire":50,"energy":80,"electric":70,
                            "cold":0,"none":30]) );
    set("aim_difficulty",
    (["critical":90,"weakest":10,"ganglion":10,"vascular":70]) );
    
    set_skill("longblade",80);
    set_skill("parry",70);
    set_skill("tactic",80);
    set_skill("dodge",70);
    set("tactic","berserk");
    set_natural_armor(76,35);
    set_natural_weapon(35,10,15);
    set("tactic_func","my_tactic");
    set("inquiry",([
         "sadness":"@@ask_sadness"]) );
    set("exp_reward",22000);   

    wield_weapon(TWEP"key1");
    equip_armor(TOBJ"veil");
    equip_armor(TOBJ"cloak");
}

int my_tactic()
{
    object victim;
    if( random(100) > 15 || !victim=query_attacker()  ) return 0;
    if( victim->query("stop_attack") ) return 0; 
     tell_object(victim,
      "\n阿重霞召唤一堆小木柱在你的周围布下层层的结界，限制你的行动....\n\n"
          );
     tell_room( environment(victim),
      "\n阿重霞召唤一堆小木柱在四周围布下结界，限制 "+victim->query("c_name")+" 的行动.\n\n"
      ,victim  );
     victim->block_attack(10);
     victim->set_temp("msg_stop_attack",
     "( 你被层层结界限制住，无法出手攻击！)\n" );     
      return 1;
}

void ask_sadness(object who)
{
    if( !(who->query_temp("luoko_quest")) ){
    tell_object(who,@ALONG
唉..........！最近我在练剑时总有股不祥的感觉，觉得......觉得手中这把主钥似乎
越来越不顺手了，心头也不断的悸动，好像有什麽大事要发生了一样，难道守护灵龙皇
的力量要消失了吗？请你帮我调查一下好不好？我只希望那维护民族命脉的守护灵不要
出事才好..........!
ALONG
         );
     who->set_temp("luoko_quest",1);
	return ;
    }
    tell_object(who,
         "你.........你到底要不要帮人家呀？？要的话就快嘛，人家很急耶！\n");
	return ;
}

void init()
{
    ::init();
    add_action("do_report","report");
}

int do_report(string str)
{
    string *name;
    name = this_player()->query("id");
    
    if( !str || str != "fine") {
    write(@FINE
阿重霞睁大眼睛，期待著你对她说：龙皇没事了(fine)！！
FINE
         );
    return 1;
    }
    if( !this_player()->query_temp("seed_ok")==1 )
    return notify_fail(
    "阿重霞破口骂道：哼！你想骗我？我知道你根本就没真心帮我，不里你了！\n");
    
  if( (int)this_player()->query_temp("luoky_killer")==1 ){
     write("虽然我很感谢你为我解忧，但你杀了我妹妹的宠物，还是不可饶恕，死吧\n");
     command( "kill "+name[0] );
     return 1;
     } 
    
    this_player()->delete_temp("seed_ok");
    if( (int)this_player()->query_quest_level("save_tree") < 1 ) {
    write("阿重霞很高兴的说：太好了，真谢谢你，我又可以专心练剑了！\n");
    this_player()->finish_quest("save_tree",1);
    write("你已经完成了这个任务，你得到1000点经验值\n");
    this_player()->gain_experience(1000);
    return 1;
    }
    write("阿重霞公主微笑的说道：谢谢你再次帮我解除心中的忧虑，谢谢！\n");
    return 1;
}       

void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}
    

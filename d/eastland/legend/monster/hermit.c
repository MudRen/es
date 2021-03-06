#include "../legend.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "hermit", "隐者" );
    add( "id",({"hermit"}) );
    set_short( "隐者");
    set_long(@LONG
一位年约八、九十岁的老人，他隐居在这里己经有四、五十年了，因为时间太久，
也就忘了原来姓什名什，只知道他在五十多年前是位活人无数的神医，至於他为什
麽会待在这里，却没人知道究竟。隐者站在这里，聆听泉水声，他似乎若有所思，
想得出神了，一点也没发觉到你的存在，看他悠闲自在的样子，相信你也不忍心去
打扰他。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","healer");
    set("age",89);
    set("gender","male" );
    set("alignment",6000);
    set("weight",600);
    set_perm_stat("str",20);
    set_perm_stat("dex",26);
    set_perm_stat("int",28);
    set_perm_stat("kar",30);
    set("hit_points",550);
    set("max_hp",550);
    set_natural_armor(55,50);
    set_natural_weapon(28,6,8);
    set_skill("dodge",80);
    set_skill("parry",70);
    set_skill("dagger",90);
    set_skill("anatomlogy",100);
    set("special_defense", ([ "all": 50,"none":30]) );
    set("aim_difficulty",
    (["critical":65,"vascular":20,"ganglion":70,"weakest":65]) );
    set("stun_difficulty",90);
    wield_weapon(LWEAPON"ice_needle");
    set("chat_chance",10);
    set( "att_chat_output", ({
        "隐者道：可恶！竟敢打扰我的清静，看我好好教训你！\n"
    }) );
    set("inquiry", ([
           "美容":"@@ask_buty",
         "beauty":"@@ask_buty",
     "兜率弥陀珠":"@@ask_ball",
           "ball":"@@ask_ball",
         "三珠树":"@@ask_tree",
           "tree":"@@ask_tree"
    ]) );
    set("tactic_func","my_tactic");
}        
void ask_buty(object asker)
{
write(@C_LONG
隐者说道：你要美容喔？你已经这麽美了，还要更美喔？会不会太贪心咩？
你向他解释了半天．．
隐者说道：你如果要更美的话可以去找传说中的「朱果」，「朱果」在那儿我是不知
　　　　　道，不过书中有记载，「朱果」生长在「三珠树」上，约每千年开花一次
　　　　　五百年才结一次果，相当珍贵无比。但是，在「三珠树」旁有神兽看守，
　　　　　并不是那麽容易取得，切记切记。

隐者说完後，继续在一旁静思。　　　　   

C_LONG
      );
}
void ask_ball(object asker)
{
write(@C_LONG
隐者说道：兜率弥陀珠?
隐者说道：一个很好的东西啊，你不会用？记著，你只要 ( use_lifeball )
　　　　　就可以了。
C_LONG
      );
}
void ask_tree(object asker)
{
write(@C_LONG
隐者说道：一般来说，心地极善良的人才有缘看到「三珠树」，如果你觉得不够
　　　　　善良，不妨到沼泽里多砍几只坏的怪物。如果，你有缘看到「三珠树」
          ，不妨摇摇树干，说不定会有「朱果」掉下来。
C_LONG
      );
}
int my_tactic()
{
     object victim;
     int select;
          
     if (!(victim= query_attacker())) return 0;
     select=random(20);
     if ( select > 13 ) set("aiming_loc","critical");
     else if ( select > 11 ) set("aiming_loc","ganglion");
     else if ( select > 3 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
          if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
          else set("aiming_loc","vascular");
     }
     return 0;
}
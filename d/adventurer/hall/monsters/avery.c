#include "mudlib.h"
#include <daemons.h>
#define AIM ({ "ganglion","vascular","weakest"})

inherit "/d/adventurer/adv_trainer";
inherit MONSTER;

void init()
{
npc::init();
adv_trainer::init();
add_action("do_list","list");
}
void create ()
{
 //   int i;
 //   i = random(2);
	::create();
    set_level(19);
    set_name("Great Avery","大冒险家  艾佛瑞");
    add("id",({"avery","great","adventurer"}) );
    set_short("大冒险家  艾佛瑞");
	set_long(@C_LONG
    大冒险家  艾佛瑞是亚默长老最得意的弟子，不仅尽得亚默长老的真传，更在他冒
险的生涯中，学得了许多新技巧。这次他是受亚默长老所托，在此训练立志以冒险为终
身职业的冒险者。
他现在正用著一种高傲不屑的眼光打量著你。
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",28);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",30);
    set_skill("whip",100);	
    set_skill("dodge",80);
    set_skill("parry",100);
    set_skill("anatomlogy",55);
    set ("max_hp",1300);
    set ("hit_points",1300);
    set( "chat_chance",12);  
    set("chat_output",({"艾佛瑞自言自语: 都是些扶不起的阿斗...\n"}));
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(35,22,34);
    set_natural_armor(70,40);
    set ("aim_difficulty",([ "weakest":50,"vascular":30]) );
    set("special_defense", (["fire":90,"none":20]) );
    set( "aiming_loc", "weakest" );
//    AIM[i] );
    set( "tactic","berserk" );
    set ("weight", 400);
    wield_weapon( "/d/adventurer/hall/weapons/avery_whip" );
    set("inquiry",([
        "train" : "@@ask_train",
        "polemic" : "@@ask_polemic", 
        "trading" : "@@ask_trading",
        "ethics" : "@@ask_ethics",
        "diagnose" : "@@ask_diagnose",
        "hang" : "@@ask_hang",
        "natural_history" : "@@ask_natural",
        "green-magic" : "@@ask_green"
        ]));
    set("tactic_func","special_attack");
    set_lessons( ([
	"polemic": ({ 120, 50, 10 }),
	"trading": ({ 150, 70, 10 }),
	"ethics": ({ 130, 50, 20 }),
	"diagnose": ({ 120, 60, 20 }),
	"hang": ({ 220, 90, 50 }),
        "natural_history": ({ 150, 100, 40 }),
        "target": ({ 200, 50, 70 }),
      "concentrate": ({ 200, 50, 70 }),
        "green-magic": ({ 200, 50, 70 }) 
	]) );
}
int special_attack()
{
        int i;
        if(random(10)<7) return 0;
        i = random(2) ;
        set( "aiming_loc", AIM[i] );
        return 1;
}        

void ask_natural()
{
   if ((string)this_player()->query("class") != "adventurer" ) {
       write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
           return ;
   }
   
   write("大冒险家  艾佛瑞说道: 博物学可以让你认识一些常见的自然物，你可\n"
         "以用 explore 指令在野外寻找到他们。你可以打help explore得到更多\n"
         "的资讯。\n");
   return ;
}
void ask_train()
{  
     if ((string)this_player()->query("class") != "adventurer" ) {
     write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ; 
     }
     write("大冒险家  艾佛瑞说道: 没错，我可以教你们一些平常学不到的技能。\n"
           "但前提是平均冒险度要够高，你可以用list指令来看目前你能学什麽。\n");                     
    return ;
}
void ask_polemic()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
   return ;
    } 
    write("大冒险家  艾佛瑞说道: 学会辩术，你将拥有说服他人的能力，遭受敌人攻击时\n"
    "也可以利用贿赂(bribe)使敌人停止攻击你，可说是一个保命的技能。\n");
   return ;
}
void ask_trading()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ;
    }
    write("大冒险家  艾佛瑞说道: 学会交易技巧，可使你买卖物品的技巧更为高超，不但\n"
    "不会被奸商欺骗，还可以从中获得应有的利益，可说是一个赚钱的技能。\n");
   return ;
}
void ask_ethics()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ;
    }
    write("大冒险家  艾佛瑞说道: 伦理学主要在教人明辨是非，知道什麽是对的，什麽\n"
    "是错的，如果你在伦理学上下功夫的话，就可以从一个人的言行举止，大致上判\n"
    "断出一个人的善恶，这个技能在你使用consider 指令的时候会自动使用。\n");
   return ;
}
void ask_diagnose()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ;
    }
    write("大冒险家  艾佛瑞说道: 诊断这个技能能够使你知道自己或他人的状态\n"
    "在攻击或防御时知道敌人的状态，能够使你远离危险。\n"); 
   return ;
}
void ask_hang()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ;
    }
    write("大冒险家  艾佛瑞说道: 绞杀这个技能能够使你使用长鞭类武器\n"
          "绞杀敌人，若施术成功，敌人会受伤且暂时不能行动。\n");
          return ;
    }
void ask_green()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
    return ;
    }
    write("大冒险家  艾佛瑞说道: 极高等级的冒险者，由於累积了许多的\n"
          "经验与智慧，因此具有基本的绿魔法能力，但是我并不教授咒文\n"
          "你需要自己去发现并学习它 。\n");
    return ;
    }



int check_trainee(object trainee)
{
    if( (string)trainee->query("class")=="adventurer" && (int)trainee->query_level() > 4 )
    return 1;
    else
    return notify_fail(
    "大冒险家  艾佛瑞说道: 我只教够资格的冒险者，你的条件不合！\n");
}
int do_list()
{
     int explore,total_points,EXPLORE1;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("大冒险家  艾佛瑞说道: 回你自己工会去吧...\n");
     return 0;
     }
     if ( EXPLORE1 < 1000 ) {
     write("艾佛瑞说道: 以你目前的能力，还不能在我这儿学习任何技能...\n");
     return 1;
     }
     write("在这里你所能训练的技能有:\n");
if ( EXPLORE1 > 6999 )
    write("\n    目标(target)                   ( 经验值比例 = 200%, 上限 =  50 )"
 "\n    专心(concentrate)              ( 经验值比例 = 200%, 上限 =  50 )" 
"\n    绿魔法(green-magic)            ( 经验值比例 = 200%, 上限 =  50 )");  
     if ( EXPLORE1 > 4999 )
     write("    绞杀(hang)                     ( 经验值比例 = 220%, 上限 =  90 )");
     if ( EXPLORE1 > 3999 )
     write("    博物学(natural_history)        ( 经验值比例 = 150%, 上限 = 100 )");
     if ( EXPLORE1 > 1999 )
     write("    诊断(diagnose)                 ( 经验值比例 = 120%, 上限 =  60 )"
           "    伦理学(ethics)                 ( 经验值比例 = 130%, 上限 =  50 )");
     if ( EXPLORE1 > 999 )
     write("    交易(trading)                  ( 经验值比例 = 150%, 上限 =  70 )"
           "    辩术(polemic)                  ( 经验值比例 = 120%, 上限 =  50 )\n");
     return 1;
}    

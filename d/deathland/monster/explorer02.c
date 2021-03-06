#include "../echobomber.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	
	::create();
	set_level(14);
	set_name( "vampire explorer Simonleck","吸血鬼探险家西蒙雷克");
	add ("id", ({ "vampire", "explorer","simonleck" }) );
	set_short("吸血鬼探险家西蒙雷克");
	set_long(@DESC
吸血鬼探险家西蒙雷克,一个喜爱冒险的吸血鬼,曾经旅行过很多地方.
他的经历丰富,如果你和他交谈的话,你将可见到一个可以连续说话.
好几天而不用喝水的超人.
DESC
    );
    set("alignment",-550);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "个" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "kar", 22 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon( 26, 12, 15 );
	set_natural_armor( 80, 12 );
    set ("weight", 300);
    set ("chat_chance", 10);
    set("chat_output",({
        "这吸血鬼探险者笑著对你说:要不要听听我的故事(story)啊.\n"
        }));
    set_skill("dodge",90);
    set_skill("chain",100);
    set_skill("parry",70);
    set("special_defense",(["all":25]));
    set( "inquiry", ([
         "troll" : "@@ask_troll",
         "mine"  : "@@ask_mine" ,
         "hell"  : "@@ask_hell" ,
         "story" : "@@ask_story",
         "chain" : "@@ask_chain",
         ]) );
    wield_weapon(Weapon"/chain02");     
    set_lessons(([
       "chain": ( { 250,75 } )
       ]) );
}

void ask_story(object who)
{
    tell_object(who,"你想听那一段故事?大战巨人(troll),矿坑历险(mine)\n或是神游地狱(hell)呢?\n"
                );
    return ;
}

void ask_troll(object who)
{
     tell_object(who,@MSG1
有一次我不小心走进了巨人的领域,和可怕的巨人打了起来.
无论我如何的卖力,我就是无法把它给作掉,在数百回合之後
,我感觉到一种可怕的魔力慢慢地逼近我,在这麽多年的冒险
生涯里,我从未像那一次做那麽正确的判断,我以极快的速度
逃离,後来一个有经验的矮人老战士告诉我说,那是巨人大祭
师瑞哈得瑞德屈里出巡的前召,而从没有任何人能够独自见到
他而还活在这世界上的.
哈哈...
活著是件很快乐的,不是吗?
MSG1
                 );
     return ;
} 

void ask_mine(object who)
{
     tell_object(who,@MSG2
矮人矿坑,一个充满惊喜的地方,我曾拿著十字镐到处地挖挖掘掘,
倒也发了一笔小财, 其中有一次我遇见了一只奇怪的眼魔,我与它
的交手之中它身上的一件东西满有趣的,当然我并不强求你,但是如
如果你能把它带来给我的话,或许你能有意想不到的收获呦.
MSG2
                 );    
     return;
}

void ask_hell(object who)
{
     tell_object(who,"地狱,你还没有去过吗,死一次你就知道了\n西蒙雷克笑笑著对你说\n");
     return ;
}

void ask_chain(object who)
{
     
     if (! (who->query_temp("echo_chain")) ) 
        {
          tell_object(who,"西蒙雷克摇摇头说,我不知道.\n");
          return ;
        }
     else
       {
        tell_object(who,"我的流星□技巧是一个东方武术家教的,你要学习吗\n");  
        return ;
       }
}

int accept_item(object who,object item )
{
    if( (item->query("echo_chain_need")) )
      {
        who->set_temp("echo_chain",1); 
        if((string)who->query("class")=="knight")
          tell_object(who,@MSG3
谢谢你,假如你是个骑士的话,或许我可以教你流星□(chain)
的技巧,但是你需要较高的经验值去学习,因为我不是一个好老师.
MSG3
          );
        else 
          tell_object(who,@MSG4
谢谢你,我想你对於武器的领悟力不够,我并不能帮助你什麽
但还是很感谢你.
MSG4
          );
        who->set_explore("deathland#35");
        item->remove();
        return 1;
      }
    tell_object(who,"谢谢你,我最喜欢收集物品了.\n");
    return 0;
}

int check_trainee(object who)
{
    if ((string)who->query("class")!="knight" || !who->query_temp("echo_chain"))
      return 0;
    else return 1; 
}
void init()
{
	teacher::init();
	npc::init();
}

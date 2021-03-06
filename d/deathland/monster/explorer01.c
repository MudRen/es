
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(13);
	set_name( "orc explorer Lawierda","半兽人探险家兰耳达");
	add ("id", ({ "orc", "explorer","lawierda" }) );
	set_short("半兽人探险家兰耳达");
	set_long(@DESC
半兽人探险家兰耳达,一个喜爱冒险的半兽人,曾经旅行过很多地方.
这次他听说莫拉德矮人国度的矿坑充满著财富,所以赶来这里寻宝.
DESC
    );
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "orc" );
    set( "unit", "个" );
	set_perm_stat( "str", 20 );
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon(26,10,23);
	set_natural_armor(57,17);
    set ("weight", 300);
    set ("chat_chance", 15);
    set("chat_output",({
        "这半兽人探险者挥动著他的拳头,一副嚣张的样子.\n"
        }));
    set_skill("dagger",80);
    set_skill("dodge",100);
    set( "inquiry", ([
         "lucksis" : "@@ask_lucksis",
         ]) );
    wield_weapon(Weapon"/dagger02");     
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,@MSG1
兰耳达说:我不知道为何你要提起她.
那是一段伤心的往事.我不想再提起
MSG1
                       );
     else
       {
         tell_object(who,@MSG2
兰耳达说:你是拉克希丝派来的?
我想那已经是一段往事了.虽然当时我和她有一段快乐的时光,
但是现在的我只对冒险有兴趣,你想想,前往未知的区域,到处
都是死亡和刺激,是多麽过瘾的一件事啊!
兰耳达转头继续寻找这里的秘密.


一个只会追求刺激的人对於别人的生死会在意吗?
你想现在的兰耳达与拉克希丝认识的兰耳达已经截然不同了.
MSG2
                    );
         who->set_temp("lucksis_quest/lawierda",1);             
       }
     return;
}

void die()
{
	object killer;
	killer = query("last_attacker");
	killer->set_explore( "deathland#34" );
	::die();
}


#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(5);
	set_name( "bard lucksis", "流浪诗人拉克西丝" );
	add("id",({"bard","lucksis"}));
	set_short( "a bard lucksis", "流浪诗人拉克西丝" );
	set_long(
		"A bard named lucksis. she has already searched many \n"
		"years to find her lover.\n",@DESC
一个流浪诗人拉克西丝,在向恶神 Yang 问过自己的命运後,就开始她千里
漂泊的旅程寻找她命运中的爱人(lover)
DESC
	);
	set("alignment",500);
	set_perm_stat( "dex", 7 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 17);
	set_perm_stat( "karma", 10);	
	set ("max_hp", 125);
	set ("max_sp", 0);
	set ("hit_points", 125);
	set ("spell_points", 0);
	set( "race", "human" );
	set( "gender", "female" );
	set_skill("unarmed",30);
	// set( "no_attack", 1 );
	set( "inquiry", ([
		"lover" : "@@ask_lover",
		"romance" : "@@ask_romance",
		"desyer" : "@@ask_man",
	   	"ebbruce": "@@ask_man",
		"lawierda": "@@ask_man",
		"dalifore": "@@ask_man",
	]) );
}

void init()
{
   ::init();
   add_action("suggest_who","suggest");
}

void ask_man(object who)
{
     if (!(who->query_temp("lucksis_quest"))||(int)(who->query_temp("lucksis_quest/ask"))<2)
        tell_object(who,"拉克希丝对你不理不睬.\n"); 
     else if( (int)(who->query_temp("lucksis_quest/ask") )==2 ) 
        tell_object(who,"或许他是我命运中的伴侣\n");
     else   
        tell_object(who,"我已经决定献身给 Yang 了,请你帮助我\n");
     return;     
}

void ask_romance(object who)
{
     if ( !(who->query_temp("lucksis_quest")) ||(int)(who->query_temp("lucksis_quest/ask"))==0 )
        tell_object(who,"拉克希丝说道:你觉得问人隐私是一件有趣的事吗?\n");
     else 
       {
         tell_object(who,@MSG1
拉克希丝向你小声地说道:在我旅行的数年间,我的爱情故事几乎是一片空
白,但是有几个高尚的绅士曾经温文有礼地与我共同经历过一段冒险,他们
的名字分别是兰耳达(Lawierda),底斯宜尔(Desyer),艾柏鲁斯(Ebbruce)及
戴利佛(Dalifore),当时我基於礼貌,并没有回应他们的爱意,但是流浪了这
麽多年,我已经疲倦了,希望你能帮助我,一个女孩子家总是不好意思开口 ,
麻烦你帮我问一问他们的意思,然後给我一个建议(suggest),谁将是我最好
的伴侣,谢谢你.
MSG1
         );
         who->set_temp("lucksis_quest/ask",2);
       }
     return;   
}
void ask_lover(object who)
{
     if ( !(who->query_temp("lucksis_quest")) )
        {
        tell_object(who,@MSG2
拉克希丝说道:在我旅行的数年间,我见过各式各样的人.
而我命运中的爱人........

拉克希丝长叹一声,低头不语,似乎有什麽话要说的样子.
MSG2
          );
        who->set_temp("lucksis_quest",(["ask":0,
                                      "desyer":0,
                                      "lawierda":0,
                                      "ebbruce":0,
                                      "dalifore":0,
                                        ]) );
        call_out("tellyou",10,who);
        return;
        }  
     else  /* if ( (int)( who->query_temp("lucksis_quest/ask") ) !=2 ) */
        {
          tell_object(who,@MSG3
拉克希丝说道:在我旅行的数年间,我见过各式各样的人.
而我命运中的爱人........

拉克希丝长叹一声,低头不语,似乎有什麽话要说的样子.
MSG3
          );
        }
     
     return;
} 


int tellyou(object who)
{
    if ((int)(who->query_temp("lucksis_quest/ask"))==0) {
      tell_object(who,@MSG4
拉克希丝(Lucksis)告诉你:或许你能帮助我解决这个难题
拉克希丝(Lucksis)告诉你:回来我这里,我将告诉你关於我的罗曼史(romance)
MSG4
               );
      who->set_temp("lucksis_quest/ask",1);
      }
    return 1;
}

int suggest_who(string str)
{
    object who;
    int *aaa,i,j;
    mapping x=(["desyer" :"底斯宜尔 ","lawierda":"兰耳达 ",
                "ebbruce":"艾柏鲁斯 ","dalifore":"戴利佛 "]);
    who=this_player();
    if (!(who->query_temp("lucksis_quest"))|| (int)(who->query_temp("lucksis_quest/ask"))!=2 )
      {
       tell_object(who,"拉克希丝瞪你一眼说:别吵我\n"); 
      }  
    else if ( (int)( who->query_temp("lucksis_quest/ask") )==2)  
        {
          aaa=values(who->query_temp("lucksis_quest"));
          for (i=0,j=0;i<sizeof(aaa);i++) j+=aaa[i];
          if ( j==sizeof(aaa)+1 )  
             {
             tell_object(who,@MSG5
当你帮我去问他们的意见时,我自己想了许多,其实一个人的生
活也不算太坏,而且经过了这麽多年的风风雨雨,我已经看开了.
我打算服侍 Yang,到冥界去当修女 
请你帮助我最後一次,送我到冥界去,谢谢你.
MSG5
              );
             who->set_temp("lucksis_quest/ask",3);
             }  
          else 
            
            tell_object(who,"拉克西丝说:麻烦你再去问问"+
            ( (int)(who->query_temp("lucksis_quest/desyer"))==0 ? x["desyer"] : ""  )   +
            ( (int)(who->query_temp("lucksis_quest/lawierda"))==0 ? x["lawierda"] :""  )+           
            ( (int)(who->query_temp("lucksis_quest/ebbruce"))==0 ? x["ebbruce"] : ""   )+
            ( (int)(who->query_temp("lucksis_quest/dalifore"))==0 ? x["dalifore"] : "" )+
            "\n然後再给我建议,谢谢你\n"
            );
         }
         
    return 1;
}

void die()
{
   object killer;
   
   killer = query("last_attacker");
   if ( !(killer->query_temp("lucksis_quest")) || (int)(killer->query_temp("lucksis_quest/ask"))!=3)
     tell_room(environment(),
        sprintf("拉克希丝说: Yang 将诅咒%s.\n拉克希丝倒地而不甘心的死去\n",killer->query("name") )
              );
   else
     {
        if ( (int)killer -> query_quest_level("lucksis_lover") < 1 )
          {
          tell_object(killer,sprintf("拉克希丝说:谢谢你超渡我,%s\n",killer->query("name")));
          killer->finish_quest("lucksis_lover",1);
          killer->delete_temp("lucksis_quest");
          killer->gain_experience(3000);
          this_player()->set_explore( "deathland#39" );
          tell_object(killer,"\n你完成了拉克希丝的命运,获得了3000点经验值.\n");
          //write_file("/log/lucksis_quest.log",
          //  sprintf("**%s finished the quests in %s.\n",
          //           killer->query("name"),ctime( time() ) ) );
          }
        else {
          tell_object(killer,sprintf("拉克希丝说:谢谢你再度超渡我,%s\n",killer->query("name")));
          this_player()->set_explore( "deathland#39" );
        }
     }  
   ::die(1);
}


#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(5);
	set_name( "bard lucksis", "����ʫ��������˿" );
	add("id",({"bard","lucksis"}));
	set_short( "a bard lucksis", "����ʫ��������˿" );
	set_long(
		"A bard named lucksis. she has already searched many \n"
		"years to find her lover.\n",@DESC
һ������ʫ��������˿,������� Yang �ʹ��Լ���������,�Ϳ�ʼ��ǧ��
Ư�����ó�Ѱ���������еİ���(lover)
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
        tell_object(who,"����ϣ˿���㲻����.\n"); 
     else if( (int)(who->query_temp("lucksis_quest/ask") )==2 ) 
        tell_object(who,"���������������еİ���\n");
     else   
        tell_object(who,"���Ѿ���������� Yang ��,���������\n");
     return;     
}

void ask_romance(object who)
{
     if ( !(who->query_temp("lucksis_quest")) ||(int)(who->query_temp("lucksis_quest/ask"))==0 )
        tell_object(who,"����ϣ˿˵��:�����������˽��һ����Ȥ������?\n");
     else 
       {
         tell_object(who,@MSG1
����ϣ˿����С����˵��:�������е������,�ҵİ�����¼�����һƬ��
��,�����м������е���ʿ����������������ҹ�ͬ������һ��ð��,����
�����ֱַ���������(Lawierda),��˹�˶�(Desyer),����³˹(Ebbruce)��
������(Dalifore),��ʱ�һ����ò,��û�л�Ӧ���ǵİ���,������������
�����,���Ѿ�ƣ����,ϣ�����ܰ�����,һ��Ů���Ӽ����ǲ�����˼���� ,
�鷳�������һ�����ǵ���˼,Ȼ�����һ������(suggest),˭���������
�İ���,лл��.
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
����ϣ˿˵��:�������е������,�Ҽ�����ʽ��������.
���������еİ���........

����ϣ˿��̾һ��,��ͷ����,�ƺ���ʲ�ỰҪ˵������.
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
����ϣ˿˵��:�������е������,�Ҽ�����ʽ��������.
���������еİ���........

����ϣ˿��̾һ��,��ͷ����,�ƺ���ʲ�ỰҪ˵������.
MSG3
          );
        }
     
     return;
} 


int tellyou(object who)
{
    if ((int)(who->query_temp("lucksis_quest/ask"))==0) {
      tell_object(who,@MSG4
����ϣ˿(Lucksis)������:�������ܰ����ҽ���������
����ϣ˿(Lucksis)������:����������,�ҽ����������ҵ�����ʷ(romance)
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
    mapping x=(["desyer" :"��˹�˶� ","lawierda":"������ ",
                "ebbruce":"����³˹ ","dalifore":"������ "]);
    who=this_player();
    if (!(who->query_temp("lucksis_quest"))|| (int)(who->query_temp("lucksis_quest/ask"))!=2 )
      {
       tell_object(who,"����ϣ˿����һ��˵:����\n"); 
      }  
    else if ( (int)( who->query_temp("lucksis_quest/ask") )==2)  
        {
          aaa=values(who->query_temp("lucksis_quest"));
          for (i=0,j=0;i<sizeof(aaa);i++) j+=aaa[i];
          if ( j==sizeof(aaa)+1 )  
             {
             tell_object(who,@MSG5
�������ȥ�����ǵ����ʱ,���Լ��������,��ʵһ���˵���
��Ҳ����̫��,���Ҿ������������ķ������,���Ѿ�������.
�Ҵ������ Yang,��ڤ��ȥ����Ů 
�������������һ��,���ҵ�ڤ��ȥ,лл��.
MSG5
              );
             who->set_temp("lucksis_quest/ask",3);
             }  
          else 
            
            tell_object(who,"������˿˵:�鷳����ȥ����"+
            ( (int)(who->query_temp("lucksis_quest/desyer"))==0 ? x["desyer"] : ""  )   +
            ( (int)(who->query_temp("lucksis_quest/lawierda"))==0 ? x["lawierda"] :""  )+           
            ( (int)(who->query_temp("lucksis_quest/ebbruce"))==0 ? x["ebbruce"] : ""   )+
            ( (int)(who->query_temp("lucksis_quest/dalifore"))==0 ? x["dalifore"] : "" )+
            "\nȻ���ٸ��ҽ���,лл��\n"
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
        sprintf("����ϣ˿˵: Yang ������%s.\n����ϣ˿���ض������ĵ���ȥ\n",killer->query("name") )
              );
   else
     {
        if ( (int)killer -> query_quest_level("lucksis_lover") < 1 )
          {
          tell_object(killer,sprintf("����ϣ˿˵:лл�㳬����,%s\n",killer->query("name")));
          killer->finish_quest("lucksis_lover",1);
          killer->delete_temp("lucksis_quest");
          killer->gain_experience(3000);
          this_player()->set_explore( "deathland#39" );
          tell_object(killer,"\n�����������ϣ˿������,�����3000�㾭��ֵ.\n");
          //write_file("/log/lucksis_quest.log",
          //  sprintf("**%s finished the quests in %s.\n",
          //           killer->query("name"),ctime( time() ) ) );
          }
        else {
          tell_object(killer,sprintf("����ϣ˿˵:лл���ٶȳ�����,%s\n",killer->query("name")));
          this_player()->set_explore( "deathland#39" );
        }
     }  
   ::die(1);
}

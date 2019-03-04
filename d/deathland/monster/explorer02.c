#include "../echobomber.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	
	::create();
	set_level(14);
	set_name( "vampire explorer Simonleck","��Ѫ��̽�ռ������׿�");
	add ("id", ({ "vampire", "explorer","simonleck" }) );
	set_short("��Ѫ��̽�ռ������׿�");
	set_long(@DESC
��Ѫ��̽�ռ������׿�,һ��ϲ��ð�յ���Ѫ��,�������й��ܶ�ط�.
���ľ����ḻ,����������̸�Ļ�,�㽫�ɼ���һ����������˵��.
�ü�������ú�ˮ�ĳ���.
DESC
    );
    set("alignment",-550);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "kar", 22 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon( 26, 12, 15 );
	set_natural_armor( 80, 12 );
    set ("weight", 300);
    set ("chat_chance", 10);
    set("chat_output",({
        "����Ѫ��̽����Ц������˵:Ҫ��Ҫ�����ҵĹ���(story)��.\n"
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
    tell_object(who,"��������һ�ι���?��ս����(troll),�������(mine)\n�������ε���(hell)��?\n"
                );
    return ;
}

void ask_troll(object who)
{
     tell_object(who,@MSG1
��һ���Ҳ�С���߽��˾��˵�����,�Ϳ��µľ��˴�������.
��������ε�����,�Ҿ����޷�����������,�����ٻغ�֮��
,�Ҹо���һ�ֿ��µ�ħ�������رƽ���,����������ð��
������,�Ҵ�δ����һ����������ȷ���ж�,���Լ�����ٶ�
����,����һ���о���İ�����սʿ������˵,���Ǿ��˴��
ʦ�������������Ѳ��ǰ��,����û���κ����ܹ����Լ���
�����������������ϵ�.
����...
�����Ǽ��ܿ��ֵ�,������?
MSG1
                 );
     return ;
} 

void ask_mine(object who)
{
     tell_object(who,@MSG2
���˿��,һ��������ϲ�ĵط�,��������ʮ�ָ䵽�������ھ��,
��Ҳ����һ��С��, ������һ����������һֻ��ֵ���ħ,������
�Ľ���֮�������ϵ�һ����������Ȥ��,��Ȼ�Ҳ���ǿ����,������
������ܰ����������ҵĻ�,�������������벻�����ջ���.
MSG2
                 );    
     return;
}

void ask_hell(object who)
{
     tell_object(who,"����,�㻹û��ȥ����,��һ�����֪����\n�����׿�ЦЦ������˵\n");
     return ;
}

void ask_chain(object who)
{
     
     if (! (who->query_temp("echo_chain")) ) 
        {
          tell_object(who,"�����׿�ҡҡͷ˵,�Ҳ�֪��.\n");
          return ;
        }
     else
       {
        tell_object(who,"�ҵ����ǡ�������һ�����������ҽ̵�,��Ҫѧϰ��\n");  
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
лл��,�������Ǹ���ʿ�Ļ�,�����ҿ��Խ������ǡ�(chain)
�ļ���,��������Ҫ�ϸߵľ���ֵȥѧϰ,��Ϊ�Ҳ���һ������ʦ.
MSG3
          );
        else 
          tell_object(who,@MSG4
лл��,������������������������,�Ҳ����ܰ�����ʲ��
�����Ǻܸ�л��.
MSG4
          );
        who->set_explore("deathland#35");
        item->remove();
        return 1;
      }
    tell_object(who,"лл��,����ϲ���ռ���Ʒ��.\n");
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

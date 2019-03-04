#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Kanni", "Թ�����" );
	add("id",({"wight","kanni"}));
	set_short( "a wight named Kanni", "Թ�����" );
	set_long(
		"a terrible evil wight.\n",@DESC
һ��Թ��, �������ֽ�������. ���Ѿ����ε����ü�����, �ƺ����������
����Ϣ������.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 55, 26, 37 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "leit":"@@ask_brother",
        "island":"@@ask_island",
        "crystal":"@@ask_crystal",
        "secret":"@@ask_secret",
        ]));
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet")) {
              tell_object(who,@MSG1
����˵:�ҵ��ֵ����ؽ��������ҵ���? 
��....
��ʵһ�ж��Ѿ�̫����,���ǵĳ��о���ͻ���, ֻ���Ҳ�����. ��һ��
Ҫ������˼Ȫ, �ҵ�����������Ȫˮ.
����̾��һ�����ּ�����˵��:
��˼Ȫ��ʵ�����ܴ�����ܵ�, �����������ֵ���������������ʱ������
�ֵ�. ����Ȫˮ�����ü�����ɫ, ��ÿһ�ֵ�Ч�ö��кܴ�Ĳ�ͬ, ÿһ
�ֶ����������Ч��. ���һ�������Ļ�, �������������Σ��, ������
��Ҳ�����˿�ͷ. �����Ҫ�ȵĻ�, ������С�ĵ�ȥ����.
������Щ�����Ѿ�����Ҫ��, ������ֻϣ�����ܹ��ڿ�����˼Ȫ��Ȫˮ,
Ϊ����, �һ��˰����Ĺ���. ���ڵ��Ҿ���Ϊ���������ϰ�Ϣ��..
ϣ�����ܹ�������..
MSG1
              ); 
              call_out("quest_info_1",5,who);
               return;
              }
     tell_object(who,
       "������ȫ������������.\n"
       );
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG2
��˼Ȫ, �������ֵ����˰�����ʱ��ŷ��ֵ�,�������Ҫ֪��������Ļ�.
�������������ҵ��ֵ�����.
MSG2
     );
}

void ask_island(object who)
{
     tell_object(who,@MSG3
�Ұ�С��, �����λ�����֮�ӵ�����, ��Ȼ����֮�����εĸĵ�, ����Ȼδ��
��ˮ��û. ��ʹ���Ѿ������������, ��Ӧ��֪����һ�������赲�����ȥ·. 
�Ǿ�����˼Ȫ�����....
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "а��Թ�鷢�����µ�Ц��,�������������ٶ����������ȡ���������.\n"
          );
      tell_room(environment(this_object()),
          "evil shadow laughs and drains the lifeforce of "+ victim->query("name")+".\n",
          "а��Թ�鷢�����µ�Ц��,�������������ٶ���"+victim->query("c_name")+"��ȥ.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",30+random(27));
      report(this_object(),victim);
      return 1;
      }
}

void quest_info_1(object who)
{
     tell_object(who,@MSG4
��ϸ����, ������Ҫ�����������˼Ȫ�ķ���
������ҵ�������ͬ��ɫ��ħˮ��, ������һ����ˮ���Ѿ������ղ����ҵĳ�
�е������֮��. ����ˮ������ˮ���ֱ���������ɭ�ֵ��ػ���������, ���
���跨�õ���, �����õ�����ˮ�� ( crystal )��, �������Ұ�, �ҽ�������
��һ������.
MSG4
     );
     return;
}

void ask_crystal(object who)
{
     object *items,*crystal;
     int i,j,k,num;
     
     crystal=allocate(3);
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if (items[i]->query("quest_item/leit_amulet")) {
             for(j=0;j<sizeof(items);j++) 
               if ( (num=(int)items[j]->query("echo_crystal")) ) 
                 crystal[num-1]=items[j];  
             for(j=0;j<3;j++)
               if (!crystal[j]) { k=1;break; } 
             if (!k) {
                for(j=0;j<3;j++)
                  crystal[j]->remove();
                tell_object(who,
                "�ܺ�,���ҵ���������ˮ��, �����ҽ�Ϊ������һ��ˮ���ſ�.\n�Ե�.....\n"
                );  
                call_out("quest_info_2",10,who,items[i]);
               }
             else
             tell_object(who,
             "������������ˮ��������! ������˼Ȫ��Ҫ������ħˮ��.\n"
             );  
             return;
           }
        else break;
        }
     tell_object(who,
       "������ȫ������������.\n"
       );
     return;           
}

void quest_info_2(object you,object box)
{
     
     tell_object(you,@MSG5
�Ұ�ˮ���ſ���������, ���ˮ����������ͨ���ڻҰ�֮������ɽ��������.
����˼Ȫ����ھ���������.......
Ȼ���㻹��Ҫһ�����������ȥ��װ��˼��Ȫˮ�����Һ�, �Ǹ�ƿ����������
��֮��, ���������������µ���ʴ, ���Ѿ����Եֵ�ס��˼Ȫ��������, ��
�����ҵ���ƿ��, ����ˮ���ſ�������ƿ������. �����ҵ���ƿ�ӵ�ʱ��, 
�ǵ��ٻ�������, �ҽ�������������Ҫ���Լ���˼Ȫ�Ĵ�����(secret).
MSG5
     );
     you->set_explore("deathland#32");
     box->set("quest_item/crystal_card",1);
     if ((int)you->query_quest_level("queen_smile") < 2 ) 
       you->finish_quest( "queen_smile" , 2 );
     return;
     
}

void ask_secret(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/black_bottle")) {
              tell_object(who,@MSG6
�㷢����ƿ����, �ܺ�, ���㵽����˼Ȫ֮��,������ƿ��װ��(fill)
��ɫ��Ȫˮ, ��������, �ҵ���ԸҲ�������.
MSG6
              ); 
              call_out("quest_info_3",5,who);
               return;
              }
     tell_object(who,
       "���᲻�ش��������.\n"
       );
     return;
}

void to_check_something()
{
     object *items,who;
     int i;
     
     who=this_player();
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if ( (string) items[i]->query("quest_action/bottle_lock")== "leit" ) { 
             tell_object(who,
             "����ҵ��ֵܴ�������??,���ͷ�������?\n"
             );
             }
           else if ((int)items[i]->query("quest_action/muse_filled")==8) {
             tell_object(who,@MSG7
�����߽�����ʱ, ���ᷢ�����Ѿ�װ���˰�ɫ����˼Ȫˮ....
����˵: 
лл��İ�æ, �ҵ���Ը����ܹ������........
��ʱ�����������Ȫˮ.
������˵��:
�ҵ������Ѿ�������ƽ����, �����������Ѿ�û������ֵ����������,
������ϣ�����ܰ�������һ����, �ҵ��ֵ�������Ȼʹ��ػ��������
����, �ұ��뿪����, ϣ�����ܰ�������.
��ʱ�����һ��СС��ƿ���ø���.��˵
�����һ���Ŵ���ħ��ƿ, ���԰���ȥ����������ס, �����������
�ܰ����ֵ����ص���������. ���������֪������������ʹ�÷���.
�ٶ��鷳����.
MSG7
             );
             items[i]->set("quest_action/muse_filled",0);
             items[i]->set("quest_item/ancient_bottle",1);
             who->set_explore("deathland#34");
             }
           return;
           }
     return;
}

void init()
{
   ::init();
   to_check_something();
}

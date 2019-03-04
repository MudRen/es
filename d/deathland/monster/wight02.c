#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Leit", "Թ������" );
	add("id",({"wight","leit"}));
	set_short( "a wight named Leit", "Թ������" );
	set_long(
		"a terrible evil wight.\n",@DESC
һ��Թ��, �������ֽ�������. ���Ѿ����ε����ü�����, �ƺ����������
����Ϣ������.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 35, 16, 27 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("chat_chance",15);
    set("chat_output",({
        "Wight cries.\n",
        "��Թ��޺���, ����Ҫ��Ϣ......\n"
        }) );
    set("can_be_duranced",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "kanni":"@@ask_brother",
        "island":"@@ask_island",
        ]));
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
��˼Ȫ, �������ֵ����˰�����ʱ��ŷ��ֵ�,�������Ҫ֪��������Ļ�.
�������������ҵ��ֵܿ���.
MSG1
     );
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     tell_object(who,@MSG2
�ҵ��ֵܿ���, �����������ٵ�ʱ��, �����˳�ȥ, Ϊ�������������, ����
ȥ����˼Ȫ, �������ܸо����������ڻҰ�С����, ϣ�����ܰ�����. �����
�ܰ����ҵ��ֵܵĻ�, �ҽ���������˼��λ��.
MSG2
     );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet"))
               return;
           else {
             items[i]->set("quest_item/leit_amulet",1);
             who->set_explore("deathland#31");
             tell_object(who,
             "�����ҵĻ����,�����ῴ���⻤�����ʱ��,���ͻ�֪�����������.\n"
              );
             }
         }
         
}

void ask_island(object who)
{
     tell_object(who,@MSG3
�Ұ�С��, �����λ�����֮�ӵ�����, ��Ȼ����֮�����εĸĵ�, ����Ȼδ��
��ˮ��û. ����������˼Ȫ����ڰ�! ϣ�������ҵõ������..
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "а��Թ�鷢�����µ�Ц��,�������������ٶ����������ȡ���������.\n"
          );
      tell_room(environment(this_object()),
        sprintf("а��Թ�鷢�����µ�Ц��,�������������ٶ���%s��ȥ.\n",victim->query("c_name"))
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
      }
}

void durance(object player,object box)
{
    tell_object(player,
    "�������׽����ƿ����.\n");
    tell_room(environment(player),
        "���ر�"+player->query("c_name")+"��׽����ƿ��.\n",
      player );
    box->set("quest_action/bottle_lock","leit");   
    return ;
}

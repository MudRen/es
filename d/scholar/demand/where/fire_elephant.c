#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	 ::create();
	 set_level(19);
	 set_name( "A Silvery fire elephant", "�������" );
	 add( "id", ({ "elephant"}) );
	 set_short( "�������" );
	 set_long(
"�㿴��һͷ���µ�������������ݺݵص����㣬׼��Ҫ���㿾�� �£ᣭ�£飭��"
	 );
	 set("zapped", 0);
	 set("killer", 1);
     set("pursuing", 1);
     set_perm_stat("dex", 20);
     set_perm_stat("str", 30);
     set_perm_stat("kar", 25);
     set_perm_stat("int", 15);
     set_perm_stat("pie", 20);
     set_perm_stat("con", 30);
     set_skill("dodge",  80);
     set_natural_weapon( 65, 39, 65 );
     set_natural_armor( 150, 90 );
     set("special_defense", ([ "all" : 70, "none" : 50 ]) );
     set("aim_difficulty", ([ "critical" : 50, "vascular" : 50]) );
     set("alignment",-2000);
     set("max_hp",9000);
     set("hit_points",9000);

    set("tactic_func", "breath");
    set_c_verbs(({ "%s���Ȳ�%s", "%s��ͷײ%s", "%s������ѹ%s","%s�ñ���˦%s" }));
    set_c_limbs(({ "����", "ͷ��", "�Ų�", "����" }));
    set( "chat_chance", 5 );
    set( "att_chat_output", ({
	  "��������У��޴��ļһ֪���ҵ������˰�!!\n",
    }) );
}

// This function is called by the magic seed
void zapped()
{
		if( query("zapped") ) return;
        set("zapped",1);
        set_natural_armor( 100, 20 );
        calc_armor_class();
        set("max_hp",800);
        set("hit_points",800);
        set("special_defense", ([ "all" : 30, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 30, "vascular" : 20,]) );
        tell_room( environment(this_object()), 
@THROW
          
��������������һ����׼����������ӷɹ��������ñ����ĳ��������˽�ȥ!
    ����! ������!! �ȿ�!! �� .. �� .. ���� ...��
����������һ���������磬Ǻ�ȳ�һ���Ű��̣�ȴ��Ҳ�粻�����ˡ�

THROW
         ,this_object());
}

void die()
{
    object killer;
    
    killer=query("last_attacker");

if( (int)killer->query_quest_level("Fire_elephant") < 1 ){
	killer->finish_quest( "Fire_elephant", 1 );
	  tell_object(killer, 
@SUCCEED

����ҽ�һ����һ����ɫ��Ӱ�Ӵ�����������������һ���������·����ȥһ��޵���
������!!���۸���!!���۸���!!��Ҫȥ���ҵ����������㣬������Ͳ�Ҫ��!!!!!!��

������֪���᲻������̫����ͻȻһ��Ӱ�ӳ���������ǰ��ԭ��������������
��΢Ц��˵���������ӷ�! ��������! ��лʩ����ƶɮ�ܽ���ͷ����ƶɮ����
Ϊ������ָ��ʩ��һ����·������ʩ���������£�����ǰȥ�껨Ժ����(touch)
�ǿ���ʯ(stone)��! ��
��������˵�꣬����һ�ӣ���о�һ���â���������� ...

	[������� �������� ���񣬵õ� 15000 �㾭��]

����ع���������������ʧ����Ӱ���١�

SUCCEED
			);
        if ((string)killer->query("class")=="scholar") { 
           tell_object(killer,set_color("���ƺ�������������������˵������һֻ��ؾ��鹩��ʹ����ϣ��������������\n","HIM"));
           killer->set("demand/solid",2);
        }
	killer->gain_experience(15000);
	set("alt_corpse","NONE");
	die(1);
    } 
	else ::die();
}

void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( ��"+message+" )\n");
   return 1;
}


int breath()
{
    object victim;
    int att_type;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;

    c_name = victim->query("c_name");
    att_type = random(100);
    if( att_type < 30 ) {
	  if( this_object()->query("zapped") ) {
        tell_room( environment(this_object()), 
          "������󳤱�һ�죬��Ҫ��𹥻�"+c_name+"�������ִ��˸����磬ֻ���һ���Ű��� !\n\n"
		 , this_object() );
		return 1;
	  } else {
        tell_room( environment(this_object()), 
		  "������󳤱�һ�죬��һ�������"+c_name+"\n\n", this_object() );
		victim->receive_special_damage("fire", 50+random(12));
		report(this_object(),victim);
		return 1;
	  }
    } else if(att_type >= 30 && att_type < 50) {
      if( victim->query("stop_attack") ) return 0;
        tell_object( victim,"�������ͻȻ��ţ��������ڵ� !!\n");
        tell_room( environment(), 
          "�������ͻȻ��ţ���" + victim->query("c_name") +
          "��ĵ����ڵ� !!\n" 
         , ({ victim, this_object() }) 
        );
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","( �����ڷ����ڵأ��޷����� ! )\n");
        return 1;
	} else
	  return 0;
}

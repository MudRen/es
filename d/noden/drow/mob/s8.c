#include "../iigima.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name("eight tail snake","������� ");
        add( "id", ({ "snake" }) );
        set_short("snake","������� ");
        set_long(@C_LONG
���ţ������Ǹ�ʲ�����Ĺ��һ���а���β�͵ľ��ߣ��㼸�������ţ������
�������������ϵ���������۾���˸��ȼ�������Ĺ�â��һ��ں�ɫ����
�ף��������ǰ����䶯��β�ͣ���ʱ�ط���֨֨�����������ǿ��˵����ľ�����
C_LONG
        );
        set( "unit", "��" );
        set( "alignment", -1000 );
        set_perm_stat( "dex", 24 );
        set_perm_stat( "str", 22 );
        set("max_hp",600);
        set("hit_points",600);
        set( "weight", 3000 );
        set( "special_defense", ([ "all":20,"evil":80,"fire":50,"none":5]) );
        set( "aim_difficulty", ([
            "ganglion" :10, "weakest" :20, "vascular" :10 ]) );
        set_natural_armor( 75, 20 );
        set( "natural_weapon_class1", 29 );
        set( "natural_min_damage1", 35 );
        set( "natural_max_damage1", 45 );
        set_skill( "dodge",90 );
        set_c_limbs( ({ "ͷ��", "�Ӵ�����", "β��" }) );
        set_c_verbs( ({
                       "%s��ͷ�ſ����죬��%sҧ��ȥ��",
                       "%s˦������ͷ����%sײ�˹�ȥ��",
              }));
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "��᪴��߷���֨֨�Ľ�����\n",
                "��᪴�����Ѫ����۾������㣡\n",
                "�������Χ��������Ļ�ɫ������...\n",
                        }));
        set("tactic_func","special_attack");
        set( "killer", 1 );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);

  if (random(22)<7) {
    tell_room(environment(this_object()),
"��᪴��߷����̶��ļ�У����˦������β�ͣ��γ�һ��������������ɨǧ��\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);
    return 1;
  }
  if (random(25)<7) {
    tell_room(environment(this_object()),
"��᪴����ſ�Ѫ���ڣ�ͻȻ�����ǧ���������������ˣ�\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  if (random(33)<7) {
    tell_room(environment(this_object()),
"��᪴��ߵĻ��˫��ŭ���ķ�������β�;��������������˼䣬�񱩳�������ڳ�
���е��ˣ���\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+20);
    return 1;
  }
}
void announce( string c_msg )
{
        object *usr;
        int i;
        usr = users();
        for( i=0; i<sizeof(usr); i++ ) {
                if( !environment(usr[i]) ) continue;
                tell_object( usr[i], c_msg);
        }
}
void die()
{
        object obj;
        obj = query("last_attacker");
        if (obj->query_temp("drow_certi") != 3)
        {
	tell_room(environment(obj),
		"���߿��һ�������ڵ��ϣ����ˡ�",this_object() );
	::die(1);
        }

        announce(
        "ŵ�ٻʹ��ĵص��²��ϴ�������ļ����....\n"
        "����ŵ�ٻʳǲ��ϵ�����!!\n");
        if( (int)obj->query_quest_level("drow_disaster") < 1 )
        {
        obj->finish_quest("drow_disaster",1);
        tell_object( obj, "���Ѿ�����������, ��õ�10000�㾭��ֵ��\n" );
        obj->gain_experience(10000);
        }
        ::die(1);
}


#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "worker", "ɨ�ع�" );
        set_short( "ɨ�ع�");
        set("unit","λ");
        set_long(@LONG
ɨ�ع���ְ����ǰ�����ɨǬ�����ø�λ����ܺúõ�����������У�
��ҪС����ɨ�ع��Ĺ������ܰѵ�ɨ��һ����Ⱦ�Ƿǳ������׵��£����ŵĻ�
���Լ�ȥ���Կ���
LONG
        );
        set("alignment",1000);
        set("wealth/silver",50);
        set("gender","male");
        set("race","dwarf");
        set("max_hp", 600);
        set("hit_points", 600);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 18);
        set_perm_stat("kar", 23);
        set_natural_weapon( 15, 7, 18 );
        set_natural_armor( 58, 30 );
        set_skill("dodge",100);
        set_skill("blunt",100);
        set("chat_chance",5);
        set ("chat_output",({
           "ɨ�ع�˵����ɨ����һ��������Ψ�������ĸ��ֲ���ɨ��������\n"
        }));
        set("moving",1);
        set("speed",25);
        set("patrol",({"south","south","north","north"}));
        set("tactic_func","special_attack");
        wield_weapon( OWEAPON"broom" );
        equip_armor( OARMOR"glove2" );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);
  
  if (random(10)<7) {
    tell_room(environment(this_object()),
     "\nɨ�ع�ʹ��ɨ�ؽ�����һʽ��˫����סɨ��һ�ˣ����ٻӶ����ó�һȦ�ƹ⣬�����еĵ�����ȥ��\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);  
    return 1;
  }

  if (random(10)<7) {
    tell_room(environment(this_object()),
      "\nɨ�ع�ʹ��ɨ�ؽ����ڶ�ʽ��������һ���������ֳ�ɨ��һ�ˣ�һ���̳�����ʯ���쾪���������֮�ƣ������ݺ�ȫ����\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  tell_room(environment(this_object()),
   "\nɨ�ع�ʹ��ɨ�ؽ�������ʽ�����ֳ�ɨ�ѻ����ӳ���ͻȻ����һ�䣬����ɨ�������߰�Ĵ���ÿ�����˵��ʺ�\n\n"
  ,this_object());
  while(i--)
    victim[i]->receive_damage(random(10)+20);
  return 1; 
}

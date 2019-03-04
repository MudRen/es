#include "../legend.h"
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"
inherit MONSTER;

void create()
{
  ::create();
  set_level(19);
  set_name("crimson toad", "ç�����");
  add( "id", ({ "toad" }) );
  set_short("ç�����");
  set_long(
    "һֻСС�ĸ�󡣬���������磬����ͨ��ʤѪ���������鷢��������⡣��\n"
    "��΢�ţ���¹�Ĥ�𶯣�����һ������������ţ����ȴ��Ϊ����������ƽ��һ\n"
    "���ף��������ۼ���������������˴�С�ĸ���Ȼ���ĳ���������죮\n"
    );
  set( "race", "amphibia" );
  set( "unit", "ֻ" );
  set( "alignment", -3000 );
  set( "exp_reward",50000 );
  set_natural_armor( 80, 30 );
  set_natural_weapon(80,55,65);
  set( "max_hp", 1000 );
  set( "hit_points", 1000 );
  set_skill("dodge",100);
  set_perm_stat( "int", 30 );
  set_perm_stat( "dex", 30 );
  set_perm_stat( "kar", 40 );
  set( "killer", 1 );
  set( "time_to_heal", 50 );
  set("aim_difficulty",([ "critical":50,"ganglion":100 ]) );
  set("stun_difficulty",70);
  set("special_defense", (["all":75,"divine":10,"none":30]) );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "��ͷ", "ǰ��", "���" }) );
  set_c_verbs( ({ "%s���Ѫ��ɫ����ͷ����%s" ,
                  "%s�͵�����һͷײ��%s",
                  "%s��%s���һ�ڶ���"
                  }) );
}

int emit_poison()
{
  object *victim;
  int i,j;

  if( random(20)>6 || !(victim= query_attackers()) ) return 0;
  
  i=sizeof(victim);
  if ((j=random(14))>10) {
    tell_object( environment(this_object()),
      "\nͻȻ��ç�����Ծ�����ţ�����һ�����³�һ�ŵ����ĺ�����������....\n\n"
    );
    while(i--) {  
      (CONDITION_PREFIX + "simple_poison")->apply_effect( victim[i], 5, 20 );
      (CONDITION_PREFIX + "slow")->apply_effect( victim[i], 5, 5 );
      (CONDITION_PREFIX + "weak")->apply_effect( victim[i], 5, 5 );
      victim[i]->receive_special_damage("acid",50);
      report(this_object(),victim[i]);
    }   
    return 1;
  }
  else if (j>5) {
    
    tell_object( environment(this_object()),
      "\nֻ��һ�ź�����������ܷɴܣ���һ��С�ľͱ�ҧ���ˣ��˿������������Ѫ..\n\n"
      ); 
    while (i--) {
      (CONDITION_PREFIX + "simple_poison")->apply_effect(victim[i],5,15 );
      (CONDITION_PREFIX + "bleeding")->apply_effect(victim[i],5,20 );  
      victim[i]->receive_special_damage("acid",30);
    }   
    return 1;  
  }
  else {
    tell_object( environment(this_object()),
      "\nç����򣬽����������Ľи���ͣ��������ʮ���׻����ŵ��㶯������....\n\n"
      );
    while (i--) {
      victim[i]->block_attack(4);   
      victim[i]->set_temp("msg_stop_attack",
        "�㱻��¡��¡�������ŵĶ������ã�\n");
      victim[i]->receive_special_damage("acid",20);  
    }
    return 1;
  }
}
void die()
{
   object ball,killer;
   ball=new(LITEM"lifeball");
   ball->move(environment(this_object()));
   tell_room(environment(this_object()),
      "ç�������ǰ�Ӹ����³�һ��ɢ����ʹ�â������!\n");
   if ( killer=query("last_attacker") ) killer->add_temp("mobs",10);
   ::die();    
}
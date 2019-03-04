#include "../../takeda.h"
#include "/include/move.h"
#include <daemons.h>
#include "conditions.h"
#include "stats.h"

#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        

inherit "d/eastland/liang_shan/monster/chi_yu_group";

void create()
{
    ::create();
      set_level(18);
      set_name( "evil scholar", "а������" );
      add ("id", ({ "scholar" }) );
      set_short( "а������");
      set("unit","λ");
      set("alignment",-1300);
      set("weight",400);
      set_long(query("c_name")+"����С͵ר�õ�����С����\n");
      set( "alt_corpse", "NONE" );
      set( "moving", 1 );
      set( "speed", 40 );
      set_perm_stat( "dex", 23 );
      set_perm_stat( "str", 15 );
      set_perm_stat( "int", 30 );
      set_perm_stat( "kar", 20 );
      set_skill( "parry", query_level()*4 );
      set_skill( "sword",query_level()*4 );
      set_skill( "anatomlogy", query_level()*3 );
      set( "aiming_loc", "ganglion" );
      set("chi_yu_group",1);                   
      set("max_hp",440);
      set("hit_points",440);
      set("natural_defense_bonus",20);
      set ("natural_weapon_class1", 10);
      set ("natural_armor_class", 40);
      set ("special_defense",(["fire":-20,"cold":-20]));
      set ("gender", "male");
      wield_weapon("/d/deathland/weapon/sword03");
      set_temp("be_joke",10);
      set("class","scholar");
      set("max_sp",1000);
      set("spell_points",1000);
      set("max_fp",500);
      set("force_points",500);
      set("couple",1);
      set("stun_difficulty",40);
      set( "alt_corpse", "NONE" );
      set("tactic","flank");
      set("scholar_gonfu/song",40);
      set("attack_skill","scholar/song");
      set("embattle",
          ([ "four" : 1, "three" : 1, "two" : 1 ]));
      set( "tactic_func", "my_tactic" );
      command("party form");
}        

int can_help( object ob )
{
   if( ob->query_attacker() ) return 0;
   if( ob->query("couple")) return 1;
   return 0;
}
void make_angry(object obj)
{
   object ob1,ob2,ob3,*all,env;        
        
    if( query("have_party") ) return ;
    if( random(8) > 1 ) return ; 
    env=environment(obj);
    tell_room(env,C_NAME(obj)+
      "���:��ע�⣬�����е����....��\n"
      "һ��Ⱥ���˲�֪���Ƕ����˳�������������Χס... \n\n");
    set("have_party",1);
    set("party_num",4);
    set_temp("embattle_busy",0);
    ob1=new(TMONSTER"chi_yu/healer");
    ob1->move(env);
    ob2=new(TMONSTER"chi_yu/knight");
    ob2->move(env);
    ob3=new(TMONSTER"chi_yu/mage");
    ob3->move(env);
    ob1->set("master",obj);
    ob2->set("master",obj);
    ob3->set("master",obj);
    ob1->set_temp("leader",obj);
    ob2->set_temp("leader",obj);
    ob3->set_temp("leader",obj);
    ob1->add_temp( "protectees", ({ obj }) );
    ob2->add_temp( "protectees", ({ obj }) );
    ob3->add_temp( "protectees", ({ obj }) );
    all=obj->query_temp("party_members");
    all=all+({ob1,ob2,ob3});
    obj->set_temp("party_members",all);
    obj->add_temp( "protectors",({ob1,ob2,ob3}));
}

int my_tactic()
{
     object *all,*couples,victim,ob1,ob2,ob3;
     int i,members;     
     string name;
     
     if (!(victim= query_attacker())) return 0;
     name=lower_case(NAME(victim));
     couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
     for( i=0; i<sizeof(couples); i++ ) 
            couples[i]->kill_ob(victim);
     if ( this_object()->query("spell_points")<200 ) 
          this_object()->set("spell_points",1000);
     
     
     make_angry(this_object());
     if (!query_temp("embattle_busy")){
     switch( query("party_num") ) {
     case 2:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"�ȵ�:��������΢����!\n");
               command("embattle two at "+name); 
               return 0;
     case 3:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"�ȵ�:���������������!\n");
               command("embattle three at "+name);
               return 0;
     case 4:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"�ȵ�:�������������!\n");
               command("embattle four at "+name);  
               return 0;
     default :
            return 0;
     }}
       if (random(10) > 1) return 1;
       switch (random(4)) {
       case 0:
         tell_object(victim,set_color( "���������ͻȻ�ѿ�����ؾ�����г��˳�������ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",victim));
         tell_room(environment(this_object()),set_color("���������ͻȻ�ѿ�����ؾ�����г��˳�����"+victim->query("c_name")+"ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",victim),victim);
         victim->block_attack(2);
         victim->set_temp("msg_stop_attack", "�� �����ڱ���ؾ����ס���������ã��޷����� ��\n");
         return 0;
       case 1:
         tell_object(victim,set_color("ͻȻ����һ������������Ю������֮�ƴ������������ѿ�һ�ţ��������������һ�Ż����\n","HIR",victim));
         tell_room(environment(this_object()),set_color("ͻȻ����һ������������Ю������֮�ƴ������������ѿ�һ�ţ���������"+victim->query("c_name")+"���һ�Ż����\n","HIR",victim),victim);
         victim->receive_special_damage("fire",20);
         return 0;
       case 2:
         tell_object(victim,set_color( "��о���һ������ֱ����������껯��һ�ѱ����ڿ��з�������ͻȻ������һ������Ԫ�����ѱ������������³���������ɫ��â��\n","HIW",victim));
         tell_room(environment(this_object()),set_color( "��о���һ������ֱ����������껯��һ�ѱ�����
         ���з�������ͻȻ������һ������Ԫ�����ѱ���������"+victim->query("c_name")+"�³���������ɫ��â��\n","HIW",victim),victim);
         BLEEDING->apply_effect(victim,5,5);
         return 0;
       case 3:
         tell_room(environment(this_object()),set_color("��������һ������Ʈ����ˮ�������Ʈ�˳�����ˮ�������ִ���"+this_object()->query("c_name")+"���˿�֮�ᣬˮ��������������Ʈ���ˡ�\n","HIB",victim));
         this_object()->receive_healing(20);
         return 0;
      default: return 0;
      
    }
    return 1;
  }

void die()
{
  object killer;
  if ( !killer = query("last_attacker") ) {
  ::die(1);
  }
  else
  write(query("c_name")+"��Ϊһ�����̣���ʧ�ڿ�����...\n");
  ::die(1);
}

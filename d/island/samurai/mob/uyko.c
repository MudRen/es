#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "uyko", "���Ҿ�" );
//	add( "id", ({ "uyko" }) );
	set_short( "uyko", "���Ҿ�" );
	set_long(@AAA
����ǰ��һλ����Ľ��ͣ�����һ��ʮ��ò����������ף��������Ե�����ɫ
�����ã�һֱ����������ʱ����ȳ���Ѫ�����㻳�������ܺ���ս����
AAA
 );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 70,25 );
	set( "natural_weapon_class1", 15 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 45 ); 
        set( "time_to_heal",25);
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "dodge",80);
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"swallow_sword");    
        equip_armor(MOBJ"sakura"); 
        set("inquiry",([
            "o_i_la_shi":"@@give_ob"
            ]));
}

int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
     "\n\n�Ҿ�ͻȻԾ����У��콣һ�ӣ��ӽ����Ͼ�Ȼ�ɳ�һֻ����\n"+
     "\n��ֻ������һ������"+victim->query("c_name")+"\n\n"
      );
      dam = 20 + random(25);
      victim->receive_special_damage("fire", dam );
      report(this_object(),victim);
      return 1;
}
int give_ob(object ob)
{  
   if( this_player()->query_temp("have_get_statue") )
   {
       write(@CCC
���Ҿ�˵���������̰�ĵļһȥ���� !!! 
˵���콣һ�ӣ��������������������˺���
CCC);
     this_player()->set("hit_points",0);
     return 1;
   }    
   if( !this_player()->query_temp("calford") )
      return notify_fail("���Ҿ�������˵:С�ӣ��к�ָ�̣����������\n");
   ob=new(MIT"statue");
   this_player()->set_temp("have_get_statue",1);
   write(@AAA
���Ҿ�˵�������ǼӶ����ؽ���������İɣ���������ҿ̺��Ѿ��ܾ��ˣ���
�������������ǵ������ö��ѣ������ȿ��贵�����Ҳ�쵽�ˣ���͸Ͽ���ȥ
������������������������һ�°ɣ�


���Ҿ�˵�������Ĵ������ó�һ�����񣬷�����űߣ���


AAA
);
   ob->set("statue_getter",(string)this_player()->query("name") );
   ob->move(environment(this_player()));
   return 1;
 }


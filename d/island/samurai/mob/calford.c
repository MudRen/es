#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Ninja Calford", "���� �Ӷ�����" );
	add( "id", ({ "ninja","calford" }) );
	set_short( "Ninja Calford", "���� �Ӷ�����" );
	set_long(@AAA
����ǰ��һλ��������ߣ�����һͷ��ɫ�Ķ̷�������ɫ���۾�����
��Լֻ��ʮ�ˣ�������ѣ���Ȼ���ᵫȴ��һ���൱����������ร�
AAA
 );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
        set_perm_stat( "dex", 27 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 28 );    
        set( "max_hp",550 );
        set( "hit_points",550 );
 	set_natural_armor( 55,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry",100 );
        set_skill( "dagger",100 );
        set_skill( "dodge",100);
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"ninja_dagger");    
        equip_armor(MOBJ"ninja_vest");
        equip_armor(MOBJ"ninja_gloves");
        equip_armor(MOBJ"red_scarf");
        equip_armor(MOBJ"ninja_boots"); 
        set("moving",1);
        set("speed",45);
        set("patrol",({"south","north","east","west"}));
        set("inquiry",([
            "nakoruru":"��!����˵�ȿ���ѽ!����Ǻþ�û����������,����\n"
                       "���ֲ����뿪��,�������������� (present)����׼������,��֪����ɲ���\n"
                       "�԰�����һ��",
            "present":"@@ask_present"
               ]));
}
int ask_present(object player)
{            
write(@AAA
�Ӷ�����˵��:�����ҷ������Ҿ�����,��͸���˵(o_i_la_shi)�������
             ���ͻ�����ｻ������
AAA
);
player->set_temp("calford",1);
return 1;
}




int att_gonfus()
{
     object victim;
     int dam1,dam2,n;
     
     if( !(victim = query_attacker()) || (random(20)>4) ) return 0;
     else {
     switch (n=random(2))
{ case 0:
    {
     tell_room(environment(this_object()),
     "\n\n�Ӷ�����ͻȻ�嵽"+victim->query("c_name")+"��ǰ������������\n"+
     "\n�Ӷ�������һ���̷��ɿ�ˤ��"+victim->query("c_name")+"�ݺݵ��ڵ���ˤ��һ����\n\n"
      );
      dam1 = 15 + random(25);
      victim->receive_special_damage("electric", dam1 );
      report(this_object(),victim);
      return 1;
      }
  case 1:
     { 
       tell_room(environment(this_object()),
       "\n�Ӷ����ض�׼"+victim->query("c_name")+"������ѵ����｣\n"+
       "\n���������｣�ڻ���"+victim->query("c_name")+"ʱ��ͻȻ�ų����������\n\n"
       );
       dam2 = 15 + random(15);
       victim->receive_special_damage("electric",dam2);
       report(this_object(),victim);
       return 1;
      }
}
}
}

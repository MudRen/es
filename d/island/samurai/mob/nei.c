#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Nei", "�׵� ��Э˹.��" );
	add( "id", ({ "master","nei" }) );
	set_short( "Master Nei", "�׵� ��Э˹.��" );
	set_long(@AAA
������ǰ��һλ�൱���˵�Ů�ӣ������������������˵���ģ�����
�벻������ȻҲ����ʿ�����߲��ӵ�����֮һ�����͸�������Ϊ����
���ŵ�������������������ó�ʹ����ϵħ�������ֳ�֮Ϊ�׵ۣ�����	
AAA
 );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "female" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",950 );
        set( "hit_points",950 );
 	set_natural_armor( 55,35 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":45,"none":35 ])); 
        set( "aim_difficulty",([ "critical":100,"weakest":30,"ganglion":60,
                                 "vascular":30 ]));
        set( "stun_difficulty/ma",5);  
	set( "alignment", 1500 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "block",100);
        set_skill( "tactic",100);
        set_skill( "dodge",100);
        set("tactic","berserk");
        set( "wealth" , ([ "gold": 70 ]) );
        set( "tactic_func", "att_gonfus");
        wield_weapon(MOBJ"sword2");
        equip_armor(MOBJ"nei_cloak");
        equip_armor(MOBJ"nei_vest");
        equip_armor(MOBJ"nei_shield");
}

int att_gonfus()
{
     object victim;
     int dam,n;
     if( !(victim = query_attacker()) || (random(25)>4) ) return 0;
 else{    switch(n=random(2))
 { case 0:    
 {    
     tell_room(environment(this_object()), 
     "\n�ݴ��һ��:���ҵİԻʽ����� �׻���צն\n"+
     "\n�ݵ����ϵĽ�ɢ����һ�ɹ��׵磬��Ѹ��֮��ն��"+victim->query("c_name")+"\n\n"
       );
      dam = 25 + random(35);
      victim->receive_special_damage("eletric", dam );
      report(this_object(),victim);
      return 1;     
}
 case 1:
{      tell_room(environment(this_object()),
       "\n�ݸ�����������:��ѭ������֮Ѫ���̳����������֮��Լ\n"+
       "\n�ݸ�����������:����֮������֮�������Һ�������ס�����\n\n"
       );
       call_out("to_attack",4);
       return 1;
}
}
}      
}
int to_attack()
{   object victim;
    int dam;
    victim = query_attacker();
    if (!victim) return 1;
      tell_room(environment(this_player()),
      "\n��һ��һ�ɾ޴���׵�������������"+victim->query("c_name")+"����\n\n"
      );
      dam=35+random(45);
      victim->receive_special_damage("eletric",dam);
      report(this_object(),victim);
      return 1;
 }

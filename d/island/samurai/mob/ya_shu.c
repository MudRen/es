#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Samurai captain yashu","��ʿ�ӳ� Լ��" );
	add( "id", ({ "captain","yashu" }) );
	set_short( "��ʿ�ӳ� Լ��" );
	set_long(@AAA
����ǰ��������ʿ�ŵĶӳ�����Ȼ�����ĺ�˹�ģ���Ҫ֪�������ߵ��Ǻͳ����޹ص�
Ŀǰ��Ϊ���������ǿ��ʿ�ŵ�ս���������У�����
AAA
   );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 24 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 15 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",600 );
        set( "hit_points",600 );
 	set_natural_armor( 50,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 40 ); 
        set( "time_to_heal",35);
        set( "special_defense",([ "all":30,"none":30 ])); 
        set( "aim_difficulty",([ "critical":60,"weakest":40,"ganglion":50,
                                 "vascular":45 ]));
        set( "stun_difficulty/ma",35);  
	set( "alignment", 1000 );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 150 ]) );
        set( "tactic_func", "att_gonfus");
        wield_weapon(MOBJ"sound_blade.c");
        equip_armor(MOBJ"night_cloak.c");
        equip_armor(MOBJ"a_shu_la.c");
        equip_armor(MOBJ"mark.c");
             
}

int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
     "\nԼ�޺ȵ��������ҵı�ɱ����\n"+
     "Լ��˫����ӣ����һƬ��Ļ���������Լ�Ŀ��������޵����ӣ�����\n\n"+
     "Լ�޴��һ�������ҵġ�����衫�����ޡ��ޡ�ն��\n\n"+
     "��һ�潣Ļһ����"+victim->query("c_name")+"���£�����������ʮ���˿ڣ���\n"
      );
      dam = 30 + random(25);
      victim->receive_special_damage("cold", dam );
      report(this_object(),victim);
      return 1;
      
}

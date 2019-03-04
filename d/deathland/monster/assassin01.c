#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "shadow assassin", "ҹӰɱ��" );
	add("id",({"assassin"}));
	set_short( "an shadow assassin", "ҹӰɱ��" );
	set_long(
		"a terrible shadow assassin.\n"
		"һ�����˾��µ�ҹӰɱ�� ,������Ϣ�ı���������ר�� ,����ֻҪ�ںڰ�֮�� ,\n"
		"����û�����ܹ����������λ�� .\n"
	);
	set( "gender", "male" );
	set( "alignment", -1200 );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 100 );
	set_skill( "dagger",100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set_natural_armor(70,12);
 	set_natural_weapon(35,10,20);
    set( "special_defense", (  ["all":25, "none": 5]  ) );
    set ("aim_difficulty",([ "critical":33,"vascular":12 ]) );
    set( "tactic_func", "my_tactic");	
    wield_weapon(Weapon"/dagger04");
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "ҹӰɱ��ͻȻ������.\n" );
      tell_room(environment(this_object()),
          "ҹӰɱ��ͻȻ����"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 20 + random(30) );
      report(this_object(),victim);
      return 1;
      }
}

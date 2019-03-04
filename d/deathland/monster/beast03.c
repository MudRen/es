#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(17);
	set_name( "Beast of Forest", "ɭ���ػ���" );
	add("id",({"beast"}));
	set_short( "Beast of Forest", "ɭ���ػ���" );
	set_long(
		"a great beast protecting the forest.\n",
		"һֻ�ػ����Ұ���ɭ�ֵľ޴�ʥ��.\n"
	);
	set( "alignment", 800 );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 100 );
	set_natural_armor(80,10);
 	set_natural_weapon(37,27,30);
    set( "special_defense", (  ["all":25, "none": 25]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("wealth", ([ "gold": 150]) );
    set( "tactic_func", "my_tactic");
    
    item=new(Deathland"/object/crystal03");
    item->move(this_object());
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "�ػ���ͻȻҧ��.\n" );
      tell_room(environment(this_object()),
          "�ػ���ͻȻҧ"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 30 + random(25) );
      report(this_object(),victim);
      return 1;
      }
}

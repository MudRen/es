#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    
	::create();
	set_level(15);
	set_name( "swamp plant", "����ֲ��" );
	add("id",({"plant"}));
	set_short( "swamp plant", "����ֲ��" );
	set_long(
		"a strange black swamp plant.\n",
		"һ�������ڻҰ�������ĺ�ɫֲ��,���������ع����κ�����.\n"
	);
	set( "alignment", 0 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 95 );
	set_natural_armor(85,15);
 	set_natural_weapon(40,25,35);
    set( "special_defense", (  [ "all":25, "none": 25, "fire":-10 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set( "tactic_func", "my_tactic");
    set_c_verbs( ({ "%s���֦�����ٻ���%s"}) );
    set_c_limbs( ({ "֦��", "֦��" }) );
    
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "��ֲ������ס��������ľ���.\n" );
      tell_room(environment(this_object()),
          "This plant drain the power of "+ victim->query("name")+".\n",
          "��ֲ���"+victim->query("c_name")+"��ס���������ľ���.\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 25 + random(30) );
      report(this_object(),victim);
      return 1;
      }
}

#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(14);
	set_name( "strange jungle plant", "��ֵĴ���ֲ��" );
	add("id",({"plant"}));
	set_short( "a strange green jungle plant", "��ֵĴ���ֲ��" );
	set_long(
		"a strange green jungle plant.\n",
		"һ����ֵ���ɫ����ֲ��,�����ᶯ�ľͻ���������.\n"
	);
	set( "alignment", 0 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 16 );
	set_skill( "dodge", 95 );
	set_natural_armor(70,15);
 	set_natural_weapon(33,20,25);
    set( "special_defense", (  [ "all":25, "none": 25, "fire":-25 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set_c_verbs( ({ "%s���֦�����ٻ���%s"}) );
    set_c_limbs( ({ "֦��", "֦��" }) );
    set( "tactic_func", "my_tactic");
    
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "��ֲ������ס��������ľ���.\n" );
      tell_room(environment(this_object()),
          "��ֲ���"+victim->query("c_name")+"��ס���������ľ���.\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 15 + random(20) );
      report(this_object(),victim);
      return 1;
      }
}

#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(16);
	set_name( "death falcon", "������ӥ" );
	add("id",({"falcon"}));
	set_short( "a death falcon", "������ӥ" );
	set_long(
		"a death falcon.\n",
		"��ʱ���������������˵�������ӥ. ���ķ��и߶Ⱥܵ�, ��������\n"
		"����Ŀ�������������������������.\n"
	);
	set( "alignment",-100 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 16 );
	set_skill( "dodge", 100 );
	set_natural_armor(87,0);
 	set_natural_weapon(44,30,32);
    set( "special_defense", (  [ "all":10 , "none": 5 ]  ) );
    set ("aim_difficulty",([ "critical":40 ,"vascular":30]) );
    set ("killer",1);
    set ("moving",1);
    set ("speed",50);
    set( "tactic_func", "my_tactic");
	set_c_limbs( ({ "ͷ��", "����","���" }) );
	set_c_verbs( ({ "%s��������צ��%s׽ȥ" }) );
    
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "����ӥ����������ҧ��.\n"
          );
      tell_room(environment(this_object()),
          "����ӥ����������ҧ"+victim->query("c_name")+".\n"
          ,({victim,this_object()}) );
      victim->receive_damage( 10 + random(20) );
      report(this_object(),victim);
      return 1;
      }
}

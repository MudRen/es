
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name("octpus", "����");
	add("id",({"octpus"}));
	set_short("An octpus", "����");
	set_long(
	    "An octpus is searching the food to eat.",
	    "һֻ�޴������,���������Ĵ���Ѱ��ʳ��\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", -550 );
	set("max_hp",400);
	set("likefish",1);
	set("hit_points",400);
	set_natural_weapon(23,12,19);
	set_natural_armor(30,0);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�Ӷ����Ĵ�����%s�޴��ȥ" }) );
}

int emit_lick()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "�����������Ĵ��ְ�"+victim->query("c_name")+"��������ס\n"
		  );
	  victim->receive_damage(18+random(12));	
	  report(this_object(),victim);
	  return 1;
      }
}

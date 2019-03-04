
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("frog", "����");
	add("id",({"frog"}));
	set_short("A frog", "����");
	set_long(
	    "A frog is searching the fly to eat.",
	    "һֻ����Ѱ�Ҳ�Ӭ���Ե�����.\n"
	);
	set("race","frog");
	set("c_race","����");
	set( "unit", "ֻ" );
	set( "alignment", -50 );
	set_natural_weapon(5,2,7);
	set_natural_armor(10,0);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�ſ����Ĵ�ڣ���������ͷ��%s��ȥ" }) );
}

int emit_lick()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "���������������,�������ʮ������....\n"
		  );
	  victim->receive_damage(6+random(5));	
	  report(this_object(),victim);
	  return 1;
      }
}

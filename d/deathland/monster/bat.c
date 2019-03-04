
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name("huge bat", "������");
	add("id",({"bat"}));
	set_short("A huge bat", "������");
	set_long(
	    "A huge bat.",
	    "һֻ�޴������.\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", -200 );
	set("aggressive",1);
	set_natural_weapon(30,20,25);
	set_natural_armor(55,15);
	set( "tactic_func", "bite_you" );
	set_c_limbs( ({ "ͷ��", "����","���" }) );
	set_c_verbs( ({ "%s�ſ����Ĵ�ڣ�������������%sҧȥ" }) );
}

int bite_you()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "��޴���������������������Ѫ.\n"
		  );
	  victim->receive_damage(30+random(10));	
	  report(this_object(),victim);
	  return 1;
      }
}

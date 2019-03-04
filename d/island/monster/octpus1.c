#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("octpus", "����");
	add("id",({"octpus"}));
	set_short("����");
	set_long(@LONG
һֻ���͵����㣬���������Ĵ���Ѱ��ʳ��벻Ҫ������
LONG
	);
	set( "unit", "ֻ" );
	set( "alignment", -250 );
	set("max_hp",400);
	set("likefish",1);
	set("hit_points",400);
	set_natural_weapon(30,9,15);
	set_natural_armor(40,10);
	set( "unarmed" , 40 );
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�Ӷ����Ĵ�����%s�޴��ȥ" }) );
}

int emit_lick()
{
	object victim;

	if( random(25)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n�����������Ĵ��ְ�"+victim->query("c_name")+"��������ס\n\n"
		  );
	  victim->receive_damage(1+random(3));
	  report( victim );	
	  return 1;
      }
}

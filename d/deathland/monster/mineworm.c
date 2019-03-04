
#include "../echobomber.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("mine huge worm", "��Ӿ޳�");
	add("id",({"worm"}));
	set_short("A mine huge worm", "��Ӿ޳�");
	set_long(
		"You see a very very huge worm,which is searching food\n"
		"poisonus.\n",
	    "����һ��ʮ�־޴�Ĺֳ�,�ƺ�����һ�ڰ��������.\n"
	);
	set( "unit", "��" );
	set( "alignment", -400 );
	set("aggressive",1);
	set_natural_weapon(7,3,4);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�ſ����Ĵ�ڣ�������������%sҧȥ" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"�޳��������һ����ɫ��Ũ��Һ�壬�պ����������ǰ ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 12, 4 );
	return 1;
}

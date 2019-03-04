#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("snake", "����˿");
	set_short("����˿");
	set_long(
		"һ�����̵�����˿��\n"
	);
	set( "unit", "��" );
	set( "alignment", -300 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "emit_poison" );
	set( "chat_chance",15);
	set( "chat_output", ({
		"����˿����Ľű����ߡ�\n" }) );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}

int emit_poison()
{
	object victim;

	if( random(15)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"����˿�ſ��������ҧ�£������һ���ʹ ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 20, 3 );
	return 1;
}

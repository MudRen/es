#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("cobra", "�۾���");
	set_short("�۾���");
	set_long(
		"�����۾������൱Σ�յģ����������Ƕ����������š�\n"
	);
	set( "unit", "��" );
	set( "alignment", -500 );
        set( "killer", 1);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()),
		"�۾��ߴ�������һ�ɰ�ɫ�Ķ�Һ���պ����������ǰ ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 8 );
	return 1;
}

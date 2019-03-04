// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("hornet", "�Ʒ�");
   set_short("�Ʒ�");
	set_long(
		"�㿴��һֻ���˽еĻƷ䣬������㱻������֮ǰ�Ͽ���ɡ�\n"
	);
   set( "race", "insect" );
	set( "unit", "ֻ" );
   set( "exp_reward", 156 );
	set( "tactic_func", "sting" );
	set( "killer", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 15 );
	set( "natural_weapon_class1", 5 );
	set( "c_death_msg", "%s�������䵽���ϣ��������� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "���" }) );
	set_c_verbs( ({ "%s�������˵Ľ�������%s��ȥ" }) );
	setenv( "C_MIN", "һֻ$N���˹�����" );
	setenv( "C_MOUT", "$N��$D�߷��ߡ�" );
}

int sting()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_object( victim,
            "�Ʒ�ɵ�������ϣ���е�����һ���ʹ��\n" );
    tell_room( environment(this_object()),
            "�Ʒ�ɵ�" + victim->query("c_name") + "�����ϣ���β������һ󧣡\n",
                ({this_object(),victim}) );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
	return 1;
}

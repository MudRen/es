// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("poisonus toad", "�����");
	add( "id", ({ "toad" }) );
   set_short("�����");
	set_long(
		"�㿴��һֻ�޴����ܣ����ϳ����ʺ�ɫ�Ĵ�ߵ㡣\n"
	);
   set( "race", "amphibia" );
	set( "unit", "ֻ" );
   set( "exp_reward", 933 );
	set( "alignment", -600 );
   set_natural_armor( 15, 6 );
   set( "max_hp", 300 );
   set( "hit_points", 300 );
	set_perm_stat( "int", 2 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 8 );
	set( "aggressive", 1 );
	set( "forgetful", 1 );
	set( "time_to_heal", 5 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "ͷ��", "����", "ǰ��", "���" }) );
	set_c_verbs( ({ "%s���̵��ɫ����ͷ������%s" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
            "����ܴ�������һ�ɺ�ɫ�����壬�պ����������ǰ ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 8, 8 );
	return 1;
}

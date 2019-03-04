// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("snake", "����");
   set_short("����");
	set_long(
		"�����ߵ�ͷ�������εģ�������Сʱ������Ͽ����ģ���������ͷ������\n"
		"�󲿷����ж��ġ�\n"
	);
	set( "unit", "��" );
	set( "alignment", -300 );
   set_perm_stat( "dex", 8 );
    set( "max_hp", 300 );
    set( "hit_points", 300 );
   set_natural_armor( 30, 10 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 4 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
   set( "exp_reward", 513 );
}

int emit_poison()
{
	object victim;

   if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
           "���ߴ�������һ����ɫ�����壬�պ����������ǰ ....\n",
		this_object() );
   (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 10, 3 );
	return 1;
}

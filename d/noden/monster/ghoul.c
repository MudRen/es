// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name("ghoul", "��ɫʳʬ��");
   set_short( "��ɫʳʬ��");
	set_long(
		"���ʳʬ�����ֳ����ף�Ƥ�������ģ�����������һ�ɳ�ζ��\n"
	);
   set( "race", "undead" );
	set( "unit", "��" );
	set( "alignment", -600 );
   set( "exp_reward", 2530 );
   set( "max_hp", 350 );
   set( "hit_points", 350 );
	set( "natural_weapon_class1", 16 );
	set( "natural_min_damage1", 8 );
	set( "natural_max_damage1", 18 );
	set( "tactic_func", "emit_poison" );
	set( "wealth/gold", 25 );
	wield_weapon("/d/noden/item/bronze_claw");
	set_c_verbs( ({ "%s�ſ����죬��%sҧȥ", "%s������������%sһץ",
		"%ş����%s��ȥ" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
   if( random(20)<5) {
            tell_room( environment(this_object()),
                    "ʳʬ���������һ����ɫ�ĳ������պ����������ǰ ....\n",
			this_object() );
		(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 15, 6 );
	} else {
            tell_room( environment(this_object()),
                    "ʳʬ����һ����...��...��...���ĹֽУ�\n",
			this_object() );
            (CONDITION_PREFIX + "confused")->apply_effect( victim, 12, 5 );
	}
	return 1;
}

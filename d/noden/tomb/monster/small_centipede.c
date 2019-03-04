
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name("centipede", "���");
   set_short("���");
	set_long(
     "�㿴��һֻ��ɫ�����, һ˫�����۾���������,\n"
     "���㲻������һ������!\n"
	);
   set("race","insect");
   set( "unit", "��" );
   set( "alignment", -500 );
   set( "exp_reward", 1350 );
   set_natural_armor( 30, 15 );
   set_natural_weapon( 10, 5, 9 );
   set( "max_hp", 400 );
   set( "hit_points", 400 );
   set_perm_stat( "int", 5 );
   set( "killer", 1 );
	set( "tactic_func", "emit_poison" );
   set_c_limbs( ({ "ͷ��", "����", "�㲿" }) );
   set_c_verbs( ({ "%s��β��ɨ��%s", "%s��ͷ��ײ��%s" }) );
}

int emit_poison(object victim)
{

   if( random(20)>3 || !(victim= query_attacker()) ) return 0;
   if( random(20)<4 ) {
    tell_room( environment(this_object()),
     "\n���ͻȻ�����������, �ݺݵ�ҧ����һ��...\n",
		this_object() );
   (CONDITION_PREFIX + "weak")->apply_effect( victim, 10, 3 );
   }
	return 1;
}


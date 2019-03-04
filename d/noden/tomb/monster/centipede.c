
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(15);
   set_name("purple centipede", "�����");
   add( "id", ({ "centipede" }) );
   set_short("�����");
	set_long(
     "�㿴��һֻ�޴�������, �����Ϻ�, һ˫�����۾���������,\n"
     "���㲻������һ������!\n"
	);
   set("race","insect");
   set( "unit", "��" );
   set( "alignment", -1000 );
   set( "exp_reward", 15562 );
   set_natural_armor( 55, 34 );
   set_natural_weapon( 25, 8, 17 );
   set( "max_hp", 800 );
   set( "hit_points", 800 );
   set_perm_stat( "int", 10 );
   set( "block_aim", ({ "weakest" }) );
   set( "killer", 1 );
	set( "tactic_func", "emit_poison" );
   set_c_limbs( ({ "ͷ��", "����", "�㲿" }) );
   set_c_verbs( ({ "%s��β��ɨ��%s", "%s��ͷ��ײ��%s" }) );
   equip_armor( "/d/noden/tomb/obj/ankh" );
}

int emit_poison(object victim)
{

   if( random(20)>5 || !(victim= query_attacker()) ) return 0;
if( 2<random(20)<6 ) {
    tell_room( environment(this_object()),
       "\n�����ͻȻ�����������, �ݺݵ�ҧ����һ��...\n",
		this_object() );
   (CONDITION_PREFIX + "simple_poison")->apply_effect( victim,20,20 );
   }
   if( random(20)<3 ) {
   tell_object(victim,
       "\n�����ͻȻ���һ�ź�ɫ��������������...\n\n" );
   (CONDITION_PREFIX + "slow")->apply_effect( victim,15, 5 );
   }
	return 1;
}

void die()
{
        object killer;

        killer = query("last_attacker");
        if( killer ) killer->set_explore("noden#19");
        ::die();
}

#include "../moyada.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("killer ant", "ɱ����");
	add( "id", ({ "ant"}) );
   set_short("ɱ����");
	set_long(
		"һֻ���׶�ľ��ϣ��������������֮ǰ�Ͽ���ɡ�\n"
	);
   set( "race", "insect" );
	set( "unit", "ֻ" );
   set( "exp_reward", 247 );
	set( "alignment", -120 );
   set( "max_hp", 150 );
   set( "hit_points", 150 );
	set( "tactic_func", "big_bite" );
	set( "killer", 1 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "weight" ,100);
	set_natural_weapon( 13, 4, 7 );
	set_natural_armor( 16, 4 );
	set_perm_stat("str", 6);
	set_perm_stat("dex", 8);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	setenv( "C_MIN", "һֻ$N���˹�����" );
	setenv( "C_MOUT", "$N��$D�������ˡ�" );
	set("alt_corpse", MOYADA"obj/ant_corpse1" );
}

int big_bite()
{
	object victim;

	if( random(20)>3 || !(victim = query_attacker()) ) return 0;
    tell_object(  victim,
        "ɱ����������Ľ��ϣ��ݺݵ�һ��ҧ�£���е�һ���ʹ��\n" );
    tell_room( environment(this_object()), 
"ɱ��������"+victim->query("c_name")+"�Ľ��ϣ��ݺݵ�һ��ҧ�£�\n",
		({ this_object(), victim }) );
	SIMPLE_POISON->apply_effect( victim, 4, 5 );
	return 1;
}

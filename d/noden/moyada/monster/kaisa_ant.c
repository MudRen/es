#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("Kaisa ant", "����֮��");
	add( "id", ({ "ant" }) );
	set_short("����֮��");
	set_long(
		"ʮ�־޴�����ϣ���Ƭ���ݾ�������һ��������\n"
	);
	set( "max_hp",500);
	set( "hit_points",500);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 700 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 80, 35 );
	set_perm_stat("str",28);
	set_perm_stat("dex",20);
	set_perm_stat("con",30);
	set( "weight", 100);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
	set( "exp_reward", 8500 );
}
